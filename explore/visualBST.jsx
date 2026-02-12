import React, { useState, useEffect } from 'react';
import { Plus, Trash2, Play, RefreshCw, ChevronDown, ChevronRight, Pause } from 'lucide-react';

// --- Standard Binary Tree Node Class ---
class TreeNode {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
    // x and y are for visualization coordinates
    this.x = 0;
    this.y = 0;
    // Unique ID for animation tracking
    this.id = Math.random().toString(36).substr(2, 9);
  }
}

// --- Main Application Component ---
export default function BinaryTreeApp() {
  const [root, setRoot] = useState(null);
  const [inputValue, setInputValue] = useState('');
  const [outputMessage, setOutputMessage] = useState('Tree is empty. Add a number to start.');
  const [traversalResult, setTraversalResult] = useState([]);
  const [activeNodeId, setActiveNodeId] = useState(null); // Track which node is currently being visited
  const [animating, setAnimating] = useState(false);

  // Constants for visualization layout
  const CANVAS_WIDTH = 800;
  const NODE_RADIUS = 20;
  const VERTICAL_SPACING = 60;

  // --- Tree Logic ---

  const insertNode = (rootNode, value) => {
    if (!rootNode) {
      return new TreeNode(value);
    }
    if (value < rootNode.value) {
      rootNode.left = insertNode(rootNode.left, value);
    } else {
      rootNode.right = insertNode(rootNode.right, value);
    }
    return rootNode;
  };

  const handleInsert = () => {
    if (animating) return; // Prevent editing while animating
    const val = parseInt(inputValue);
    if (isNaN(val)) return;

    // Use functional state update to ensure we have latest root
    const newRoot = insertNode(root ? cloneTree(root) : null, val);
    
    // Recalculate positions immediately after insertion
    calculatePositions(newRoot, CANVAS_WIDTH / 2, 40, CANVAS_WIDTH / 4);
    
    setRoot(newRoot);
    setInputValue('');
    setOutputMessage(`Inserted ${val}.`);
    setTraversalResult([]);
    setActiveNodeId(null);
  };

  // Deep clone helper to allow state updates on object mutation
  const cloneTree = (node) => {
    if (!node) return null;
    const newNode = new TreeNode(node.value);
    newNode.id = node.id; // Preserve ID for stable rendering/animation
    newNode.x = node.x;
    newNode.y = node.y;
    newNode.left = cloneTree(node.left);
    newNode.right = cloneTree(node.right);
    return newNode;
  };

  const clearTree = () => {
    if (animating) return;
    setRoot(null);
    setTraversalResult([]);
    setOutputMessage('Tree cleared.');
    setActiveNodeId(null);
  };

  // --- Traversals (Return Array of Nodes now, not just values) ---

  const traverseInOrder = (node, result = []) => {
    if (!node) return result;
    traverseInOrder(node.left, result);
    result.push(node);
    traverseInOrder(node.right, result);
    return result;
  };

  const traversePreOrder = (node, result = []) => {
    if (!node) return result;
    result.push(node);
    traversePreOrder(node.left, result);
    traversePreOrder(node.right, result);
    return result;
  };

  const traversePostOrder = (node, result = []) => {
    if (!node) return result;
    traversePostOrder(node.left, result);
    traversePostOrder(node.right, result);
    result.push(node);
    return result;
  };

  const runTraversal = async (type) => {
    if (!root) {
      setOutputMessage("Tree is empty.");
      return;
    }
    if (animating) return;

    setAnimating(true);
    setTraversalResult([]);
    setActiveNodeId(null);

    let sequence = [];
    let name = "";
    
    if (type === 'in') {
      sequence = traverseInOrder(root);
      name = "In-Order";
    } else if (type === 'pre') {
      sequence = traversePreOrder(root);
      name = "Pre-Order";
    } else if (type === 'post') {
      sequence = traversePostOrder(root);
      name = "Post-Order";
    }

    setOutputMessage(`Starting ${name} traversal...`);

    // Animation Loop
    for (let i = 0; i < sequence.length; i++) {
      const node = sequence[i];
      setActiveNodeId(node.id); // Highlight Node
      setTraversalResult(prev => [...prev, node.value]); // Add to list
      
      // Wait for 800ms
      await new Promise(resolve => setTimeout(resolve, 800));
    }

    setActiveNodeId(null);
    setAnimating(false);
    setOutputMessage(`${name} Traversal Complete.`);
  };

  // --- Visualization Logic ---

  // Recursively calculate X/Y coordinates for the nodes
  const calculatePositions = (node, x, y, offset) => {
    if (!node) return;
    node.x = x;
    node.y = y;
    calculatePositions(node.left, x - offset, y + VERTICAL_SPACING, offset / 1.8);
    calculatePositions(node.right, x + offset, y + VERTICAL_SPACING, offset / 1.8);
  };

  // Flatten tree to array of nodes and edges for rendering
  const getRenderData = (node) => {
    const nodes = [];
    const edges = [];
    
    const traverse = (n) => {
      if (!n) return;
      nodes.push(n);
      if (n.left) {
        edges.push({ x1: n.x, y1: n.y, x2: n.left.x, y2: n.left.y });
        traverse(n.left);
      }
      if (n.right) {
        edges.push({ x1: n.x, y1: n.y, x2: n.right.x, y2: n.right.y });
        traverse(n.right);
      }
    };
    
    traverse(node);
    return { nodes, edges };
  };

  const { nodes, edges } = getRenderData(root);

  return (
    <div className="flex flex-col h-screen bg-slate-50 font-sans text-slate-800">
      
      {/* Header */}
      <header className="bg-slate-900 text-white p-4 shadow-md">
        <h1 className="text-xl font-bold flex items-center gap-2">
          <div className="w-8 h-8 bg-blue-500 rounded-full flex items-center justify-center text-xs">
            BST
          </div>
          Binary Search Tree Implementation
        </h1>
        <p className="text-sm text-slate-400 mt-1">
          Insert numbers. Click a traversal button to see the animation.
        </p>
      </header>

      {/* Controls */}
      <div className="bg-white p-4 border-b border-slate-200 flex flex-wrap gap-4 items-center justify-between">
        <div className="flex gap-2">
          <input 
            type="number" 
            value={inputValue}
            onChange={(e) => setInputValue(e.target.value)}
            onKeyDown={(e) => e.key === 'Enter' && handleInsert()}
            placeholder="Enter a number"
            disabled={animating}
            className="border border-slate-300 rounded px-3 py-2 w-40 focus:outline-none focus:border-blue-500 disabled:bg-slate-100 disabled:text-slate-400"
          />
          <button 
            onClick={handleInsert}
            disabled={animating}
            className="bg-blue-600 hover:bg-blue-700 disabled:bg-slate-400 text-white px-4 py-2 rounded flex items-center gap-2 transition-colors"
          >
            <Plus size={16} /> Insert
          </button>
          <button 
            onClick={clearTree}
            disabled={animating}
            className="bg-red-50 hover:bg-red-100 disabled:bg-slate-50 disabled:text-slate-400 text-red-600 border border-red-200 px-4 py-2 rounded flex items-center gap-2 transition-colors"
          >
            <Trash2 size={16} /> Clear
          </button>
        </div>

        <div className="flex gap-2 text-sm items-center">
          <span className="self-center font-semibold text-slate-500 mr-2">
            {animating ? 'Animating...' : 'Traverse:'}
          </span>
          <button onClick={() => runTraversal('in')} disabled={animating} className={`px-3 py-2 rounded border transition-colors ${animating ? 'bg-slate-100 text-slate-400 border-slate-200' : 'bg-slate-100 hover:bg-slate-200 border-slate-300'}`}>In-Order</button>
          <button onClick={() => runTraversal('pre')} disabled={animating} className={`px-3 py-2 rounded border transition-colors ${animating ? 'bg-slate-100 text-slate-400 border-slate-200' : 'bg-slate-100 hover:bg-slate-200 border-slate-300'}`}>Pre-Order</button>
          <button onClick={() => runTraversal('post')} disabled={animating} className={`px-3 py-2 rounded border transition-colors ${animating ? 'bg-slate-100 text-slate-400 border-slate-200' : 'bg-slate-100 hover:bg-slate-200 border-slate-300'}`}>Post-Order</button>
        </div>
      </div>

      {/* Main Content Area */}
      <div className="flex flex-1 overflow-hidden">
        
        {/* Visualization Canvas */}
        <div className="flex-1 overflow-auto bg-slate-50 relative flex justify-center p-8">
          <div className="relative shadow-inner bg-white border border-slate-200 rounded-lg" style={{ width: CANVAS_WIDTH, height: 600 }}>
            
            {nodes.length === 0 && (
              <div className="absolute inset-0 flex items-center justify-center text-slate-400">
                <div className="text-center">
                  <RefreshCw className="mx-auto mb-2 opacity-50" size={32} />
                  <p>Empty Tree</p>
                </div>
              </div>
            )}

            <svg width="100%" height="100%">
              {/* Draw Edges (Lines) */}
              {edges.map((edge, i) => (
                <line 
                  key={i}
                  x1={edge.x1} y1={edge.y1}
                  x2={edge.x2} y2={edge.y2}
                  stroke="#94a3b8" 
                  strokeWidth="2"
                />
              ))}

              {/* Draw Nodes (Circles) */}
              {nodes.map((node, i) => {
                const isActive = node.id === activeNodeId;
                return (
                  <g key={node.id} style={{ transition: 'all 0.5s ease' }}>
                    {/* Outer glow ring for active node */}
                    {isActive && (
                      <circle 
                        cx={node.x} 
                        cy={node.y} 
                        r={NODE_RADIUS + 8} 
                        fill="none"
                        stroke="#f59e0b"
                        strokeWidth="3"
                        opacity="0.6"
                      >
                         <animate attributeName="r" values={`${NODE_RADIUS + 5};${NODE_RADIUS + 10};${NODE_RADIUS + 5}`} dur="1.5s" repeatCount="indefinite" />
                      </circle>
                    )}
                    
                    <circle 
                      cx={node.x} 
                      cy={node.y} 
                      r={isActive ? NODE_RADIUS + 2 : NODE_RADIUS} 
                      fill={isActive ? "#f59e0b" : "#3b82f6"} 
                      stroke={isActive ? "#b45309" : "#1e40af"}
                      strokeWidth={isActive ? 3 : 2}
                      className="transition-all duration-300"
                    />
                    <text 
                      x={node.x} 
                      y={node.y} 
                      dy=".3em" 
                      textAnchor="middle" 
                      fill="white" 
                      fontSize="12px"
                      fontWeight="bold"
                    >
                      {node.value}
                    </text>
                  </g>
                );
              })}
            </svg>
          </div>
        </div>
      </div>

      {/* Footer / Console */}
      <div className="h-32 bg-slate-900 text-slate-100 p-4 font-mono text-sm overflow-y-auto">
        <div className="flex gap-2 mb-2">
           <span className="text-green-400">➜</span>
           <span>{outputMessage}</span>
        </div>
        
        <div className="flex gap-2 items-start">
          <span className="text-blue-400 whitespace-nowrap">Result:</span>
          <div className="flex flex-wrap gap-1">
            <span className="text-slate-400">[</span>
            {traversalResult.map((val, idx) => (
              <span key={idx} className="text-yellow-200 animate-pulse">
                {val}{idx < traversalResult.length - 1 ? ', ' : ''}
              </span>
            ))}
            <span className="text-slate-400">]</span>
          </div>
        </div>
      </div>

    </div>
  );
}