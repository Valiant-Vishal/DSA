import os
import subprocess

# 1. SETUP: Put the exact path you found earlier here
# (Make sure to keep the 'r' at the start)
GCC_PATH = r"c:\msys64\ucrt64\bin\gcc.exe"
C_FILE = "hello.c"
EXE_FILE = "hello.exe"

print("--- DIAGNOSTIC MODE ---")

# CHECK 1: Does Python see hello.c?
if os.path.exists(C_FILE):
    print(f"✅ Found {C_FILE}")
else:
    print(f"❌ ERROR: Python cannot find '{C_FILE}'")
    print(f"   Current folder is: {os.getcwd()}")
    print("   -> Make sure your terminal is open in the same folder as your files.")
    exit()

# CHECK 2: Does Python see GCC at the specific path?
if os.path.exists(GCC_PATH):
    print(f"✅ Found GCC at: {GCC_PATH}")
else:
    print(f"❌ ERROR: Python cannot find GCC at: {GCC_PATH}")
    print("   -> Double check the path from your screenshot.")
    exit()

# CHECK 3: Try to Compile
print("\nAttempting to compile...")
try:
    result = subprocess.run(
        [GCC_PATH, C_FILE, "-o", EXE_FILE], 
        capture_output=True, 
        text=True
    )
    
    if result.returncode == 0:
        print("✅ Compilation SUCCESS!")
    else:
        print("❌ Compilation FAILED with error:")
        print(result.stderr)
        exit()
        
except Exception as e:
    print(f"❌ Python Crashed trying to run GCC: {e}")
    exit()

# CHECK 4: Run the resulting program
print("\nAttempting to run hello.exe...")
if os.path.exists(EXE_FILE):
    # Using shell=True for the run part specifically to help Windows find the .exe
    run = subprocess.run([f".\{EXE_FILE}"], shell=True, capture_output=True, text=True)
    print("Output from C Program:")
    print("----------------------")
    print(run.stdout)
    print("----------------------")
else:
    print(f"❌ ERROR: {EXE_FILE} was not created.")