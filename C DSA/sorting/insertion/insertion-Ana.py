import timeit
import subprocess
import os

# 1. Compile the C program separate from the timer
def compile_program():
    print("Compiling C code...")
    # Adjust path if necessary. './' is safer for executables on some systems.
    compile_cmd = ['gcc', 'C DSA/sorting/insertion/insertionsort.c', '-o', 'insertionsort.exe']
    
    result = subprocess.run(compile_cmd, capture_output=True, text=True)
    
    if result.returncode != 0:
        print("Compilation failed:")
        print(result.stderr)
        return False
    return True

# 2. Define the function that ONLY runs the executable
def run_insertion_sort():
    # Only measure the execution of the already compiled exe
    exe_path = 'insertionsort.exe' if os.name == 'nt' else './insertionsort.exe'
    
    result = subprocess.run([exe_path], capture_output=True, text=True)
    
    if result.returncode != 0:
        print("Execution failed:")
        print(result.stderr)

if __name__ == "__main__":
    # Compile once
    if compile_program():
        # Run timeit on the execution function only
        # number=5 means it runs the loop 5 times
        total_time = timeit.timeit("run_insertion_sort()", globals=globals(), number=5)
        
        print(f"Total time for 5 runs: {total_time:.5f} seconds")
        print(f"Average time per run: {total_time / 5:.5f} seconds")