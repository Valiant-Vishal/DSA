import subprocess

# 1. We use the path you found in the screenshot
# The 'r' before the quote is important—it handles the backslashes correctly!


print(f"Compiling using: {gcc_path}")

# 2. Run the compilation
compile_result = subprocess.run(
    [gcc_path, "hello.c", "-o", "hello.exe"], 
    capture_output=True, 
    text=True
)

if compile_result.returncode != 0:
    print("❌ Compilation Failed:")
    print(compile_result.stderr)
else:
    print("✅ Compilation Success!")
    
    # 3. Run the new program
    # We use explicit "hello.exe" for Windows
    run_result = subprocess.run(["./hello.exe"], capture_output=True, text=True)
    print("Output from C program:")
    print(run_result.stdout)