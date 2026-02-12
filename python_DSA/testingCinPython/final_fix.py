import subprocess
import os

# Your specific path found in the diagnostic
gcc_path = r"c:\msys64\ucrt64\bin\gcc.exe"
c_file = "hello.c"
exe_file = "hello.exe"

print("--- DIRECT COMPILATION MODE ---")

# 1. CLEANUP: Try to delete the old exe first
# This confirms if the file is locked!
if os.path.exists(exe_file):
    try:
        os.remove(exe_file)
        print(f"Deleted old {exe_file}")
    except PermissionError:
        print(f"❌ CRITICAL ERROR: Cannot delete {exe_file}.")
        print("   It is currently running or locked by Windows.")
        print("   ACTION: Restart VS Code or Task Manager -> End Task 'hello.exe'")
        exit()

# 2. COMPILE: Run without capturing output (Direct to screen)
print(f"Compiling {c_file} using full path...")
try:
    # We use .call() so output goes directly to your terminal window
    exit_code = subprocess.call([gcc_path, c_file, "-o", exe_file])
    
    if exit_code == 0:
        print("✅ Compilation SUCCESS!")
    else:
        print(f"❌ GCC Failed with exit code: {exit_code}")
        exit()
except Exception as e:
    print(f"❌ Python Failed to launch GCC: {e}")
    exit()

# 3. RUN
print("\nRunning program...")
# We use shell=True here to ensure Windows handles the .exe execution correctly
subprocess.call([f".\{exe_file}"], shell=True)