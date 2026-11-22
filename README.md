# [My LinkedIn Profile](https://www.linkedin.com/in/mirzayounishussain)
amrit


# DATA STRUCTURES & ALGORITHMS (DSA)
## All Experiments in C

---

## 📂 Full Code
👉 [View Code on GitHub](https://github.com/MirzaYounisHussain/MirzaYounisHussain.github.io/blob/main/new.c)

👉 [Open Raw Code (Easy Copy)](https://raw.githubusercontent.com/MirzaYounisHussain/MirzaYounisHussain.github.io/main/new.c)

---    Sf,2-F5c%!jHahS

## 📌 How to Use
1. Open raw code  
2. Press Ctrl + A  
3. Press Ctrl + C  
4. Paste in compiler  

---
================================================================================
          OPERATING SYSTEM LABORATORY (OS LAB) — ALL EXPERIMENT CODES
          Student / Author: Mirza Younis Hussain
          GitHub Repository: https://github.com/MirzaYounisHussain/Operating-System-Lab
          Environment: Ubuntu Linux / GCC / GNU Bash
================================================================================

================================================================================
>>> Experiment 1: Installation of VirtualBox and Ubuntu OS
>>> Source File: Experiment 1/exp1_verification.sh (Bash Verification Script)
================================================================================

#!/bin/bash
# ==============================================================================
# Experiment 1: Installation of VirtualBox and Ubuntu OS
# Purpose: Environment verification script to check virtualization, kernel,
#          memory, and storage allocations inside the installed Ubuntu VM.
# ==============================================================================

echo "======================================================"
echo "Experiment 1: Ubuntu OS & VirtualBox Verification"
echo "======================================================"

echo -e "\n[1] Linux Kernel & System Architecture:"
uname -a

echo -e "\n[2] Ubuntu OS Distribution Details:"
lsb_release -a 2>/dev/null || cat /etc/os-release

echo -e "\n[3] Virtualization & CPU Hardware Details:"
lscpu | grep -E "Hypervisor|Virtualization|Model name"

echo -e "\n[4] Memory (RAM) Allocation:"
free -h

echo -e "\n[5] Virtual Disk / Storage Allocation:"
df -h /


================================================================================
>>> Experiment 2(a): Working with Basic Bash Commands
>>> Source File: Experiment 2/exp2a_basic_commands.sh (Bash Commands Script)
================================================================================

#!/bin/bash
# ==============================================================================
# Experiment 2(a): Working with Basic Bash Commands
# Commands demonstrated: pwd, ls, cd, mkdir, rmdir, rm, touch
# ==============================================================================

echo "======================================================"
echo "Experiment 2(a): Basic Bash Commands Demonstration"
echo "======================================================"

echo -e "\n[1] Print Working Directory (pwd):"
echo "Logical Path: $(pwd -L)"
echo "Physical Path: $(pwd -P)"

echo -e "\n[2] Directory Listing (ls):"
echo "-- Long format (ls -l):"
ls -l
echo "-- All files including hidden (ls -a):"
ls -a
echo "-- Sorted by time (ls -lt):"
ls -lt

echo -e "\n[3] Directory Creation & Path Navigation (mkdir & cd):"
mkdir -v -p demo_exp2/test_dir
touch demo_exp2/sample_file.txt
ls -l demo_exp2

echo -e "\n[4] File Timestamps & Modification (touch):"
touch -a demo_exp2/sample_file.txt
touch -m demo_exp2/sample_file.txt

echo -e "\n[5] Clean-up Operations (rm & rmdir):"
rm -v demo_exp2/sample_file.txt
rmdir -v -p demo_exp2/test_dir


================================================================================
>>> Experiment 2(b): Flowchart-Based Directory Management
>>> Source File: Experiment 2/exp2b_directory_tree.sh (Directory Tree Bash Script)
================================================================================

#!/bin/bash
# ==============================================================================
# Experiment 2(b): Flowchart-based Directory Management
# Creates the academic directory structure under Sem_3
# ==============================================================================

echo "======================================================"
echo "Experiment 2(b): Flowchart-Based Directory Hierarchy"
echo "======================================================"

# Create parent and sub-directories as per flowchart
mkdir -p Sem_3/OS/Theory Sem_3/OS/Lab
mkdir -p Sem_3/COA/Theory Sem_3/COA/Practical
mkdir -p Sem_3/cyber/Theory Sem_3/cyber/Lab
mkdir -p Sem_3/HSMC/Book Sem_3/HSMC/Class

echo -e "\nDirectory structure created successfully under Sem_3/:"
ls -R Sem_3


================================================================================
>>> Experiment 3(a): Sequential Command Execution & Output Redirection
>>> Source File: Experiment 3/exp3a_pipe_redirection.sh (Pipeline & Redirection Script)
================================================================================

#!/bin/bash
# ==============================================================================
# Experiment 3(a): Sequential Command Execution & Output Redirection
# Command: date; w | cat > who.txt
# Displays date on screen, and redirects 'w' output to file who.txt
# ==============================================================================

echo "======================================================"
echo "Experiment 3(a): Sequential Execution & Redirection"
echo "======================================================"

echo -e "\nExecuting: date; w | cat > who.txt\n"
date; w | cat > who.txt

echo -e "\nResulting output stored in who.txt:"
cat who.txt


================================================================================
>>> Experiment 3(b): Stream Text Transformation with Sed
>>> Source File: Experiment 3/exp3b_sed_swap.sh (Sed Word Swap Script)
================================================================================

#!/bin/bash
# ==============================================================================
# Experiment 3(b): Stream Text Transformation with Sed
# Uses sed to swap the first and second words of each line in a file.
# Command: sed -i 's/^\([^ ]*\) \(.*\)$/\2 \1/' name.txt
# ==============================================================================

echo "======================================================"
echo "Experiment 3(b): Swap First & Second Words via Sed"
echo "======================================================"

# Create sample input file
cat << 'EOF' > name.txt
Mirza Younis
Operating System
Hello World
Linux Kernel
EOF

echo "Original contents of name.txt:"
cat name.txt

echo -e "\nExecuting sed command to swap words..."
sed -i 's/^\([^ ]*\) \(.*\)$/\2 \1/' name.txt

echo -e "\nModified contents of name.txt (swapped words):"
cat name.txt


================================================================================
>>> Experiment 4: Linux Process Management Commands & Text Editing
>>> Source File: Experiment 4/exp4_process_management.sh (Process Control Bash Script)
================================================================================

#!/bin/bash
# ==============================================================================
# Experiment 4: Linux Process Management Commands & Text Editing
# Commands: ps, ps aux, top, pgrep, kill, &, jobs, nano, vi
# ==============================================================================

echo "======================================================"
echo "Experiment 4: Linux Process Management Demonstration"
echo "======================================================"

echo -e "\n[1] Check running processes in current session (ps):"
ps

echo -e "\n[2] Display all system processes (ps aux | head -n 10):"
ps aux | head -n 10

echo -e "\n[3] Start a mock background process (sleep 60 &):"
sleep 60 &
BG_PID=$!
echo "Background Process Started with PID: $BG_PID"

echo -e "\n[4] View active background jobs (jobs):"
jobs

echo -e "\n[5] Find process PID by name (pgrep sleep):"
pgrep -l sleep

echo -e "\n[6] Terminate the background process (kill $BG_PID):"
kill $BG_PID
echo "Sent termination signal to PID $BG_PID"

# Verification
sleep 1
echo -e "\n[7] Verifying termination status (jobs):"
jobs


================================================================================
>>> Experiment 5(a): Check if Argument is File or Directory
>>> Source File: Experiment 5/exp5a.sh (Shell Script (exp5a.sh))
================================================================================

#!/bin/bash
# Experiment 5(a): Check if argument is a regular file or directory

if [ -f "$1" ]; then
    echo "$1 is a file"
elif [ -d "$1" ]; then
    echo "$1 is a directory"
else
    echo "$1 does not exist"
fi


================================================================================
>>> Experiment 5(b): Convert File Names to Uppercase
>>> Source File: Experiment 5/exp5b.sh (Shell Script (exp5b.sh))
================================================================================

#!/bin/bash
# Experiment 5(b): Convert file name to uppercase

if [ -f "$1" ]; then
    new_name=$(echo "$1" | tr '[:lower:]' '[:upper:]')
    mv "$1" "$new_name"
    echo "File Name changed to Upper Case: $new_name"
else
    echo "$1 does not exist"
fi


================================================================================
>>> Experiment 6(a): User Session Duration & Login Tracker
>>> Source File: Experiment 6/exp6a.sh (Shell Script (exp6a.sh))
================================================================================

#!/bin/bash
# Experiment 6(a): Determine login / working duration of a specified user

read -p "Enter username: " user
login_time=$(who | awk -v u="$user" '$1 == u {print $3, $4; exit}')

if [ -z "$login_time" ]; then
    echo "user is not currently logged in."
else
    echo "Login time: $login_time"
fi


================================================================================
>>> Experiment 6(b): Display Lines Between Start and End Numbers
>>> Source File: Experiment 6/exp6b.sh (Shell Script (exp6b.sh))
================================================================================

#!/bin/bash
# Experiment 6(b): Display lines between start and end line numbers

read -p "Enter filename: " file
read -p "Enter starting line number: " start
read -p "Enter ending line: " end

if [ ! -f "$file" ]; then
    echo "Error: File '$file' not found."
    exit 1
fi

sed -n "${start},${end}p" "$file"


================================================================================
>>> Experiment 6(c): Delete Word Occurrences Across Multiple Files
>>> Source File: Experiment 6/exp6c.sh (Shell Script (exp6c.sh))
================================================================================

#!/bin/bash
# Experiment 6(c): Delete all lines containing a specified word in one or more files

if [ $# -lt 1 ]; then
    echo "Usage: $0 <file1> [file2 ...]"
    exit 1
fi

read -p "Enter word to delete: " word

for file in "$@"; do
    if [ -f "$file" ]; then
        sed -i "/$word/d" "$file"
        echo "Processed '$file': lines containing '$word' deleted."
    else
        echo "Warning: File '$file' does not exist."
    fi
done

echo "Operation completed."


================================================================================
>>> Experiment 7 (C Program): String Length and Substring Extraction
>>> Source File: Experiment 7/exp7.c (C Program (exp7.c))
================================================================================

#include <stdio.h>

/*
 * Experiment 7: String Operations in C
 * - Finds string length
 * - Extracts substring based on starting position and length
 */

int main()
{
    char str[100];
    int start, length, i, count = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    // Calculate length excluding newline and null terminator
    while (str[count] != '\0' && str[count] != '\n') {
        count++;
    }

    printf("Length of string: %d\n", count);

    printf("Enter Starting Position: ");
    scanf("%d", &start);

    printf("Enter Number of characters: ");
    scanf("%d", &length);

    printf("Substring: ");
    for (i = start; i < start + length && i < count; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}


================================================================================
>>> Experiment 7 (Shell Script): String Operations and Execution Timing
>>> Source File: Experiment 7/exp7.sh (Shell Script (exp7.sh))
================================================================================

#!/bin/bash
# Experiment 7: String Operations in Shell Script
# - Calculates length of string
# - Extracts substring using shell expansion

echo "Enter a String:"
read str

echo "Length of String: ${#str}"

echo "Enter String Position:"
read start

echo "Enter Number of characters:"
read length

echo -n "Substring: "
echo "${str:$start:$length}"


================================================================================
>>> Experiment 8: Dynamic Memory Allocation and Monitoring with Signals
>>> Source File: Experiment 8/exp8.c (C Program (exp8.c))
================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
 * Experiment 8: Memory Allocation and Monitoring
 * Allocates requested Megabytes of memory, touches pages,
 * and intercepts SIGINT (Ctrl+C) to safely free memory.
 */

void *ptr = NULL;

void handle_sigint(int sig)
{
    printf("\nSignal Interrupt Detected.\n");
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
        printf("Memory released.\n");
    }
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <memory_in_MB>\n", argv[0]);
        return 1;
    }

    int mb = atoi(argv[1]);
    if (mb <= 0) {
        printf("Please specify a valid positive number of MB.\n");
        return 1;
    }

    size_t bytes = (size_t)mb * 1024 * 1024;
    ptr = malloc(bytes);

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Touch memory to ensure physical page allocation (Resident Set Size - RSS)
    char *cptr = (char *)ptr;
    for (size_t i = 0; i < bytes; i += 4096) {
        cptr[i] = 1;
    }

    printf("Memory allocated Successfully (%d MB).\n", mb);
    printf("Press Ctrl+C to release memory and exit.\n");

    signal(SIGINT, handle_sigint);

    // Keep process alive so memory can be observed using 'free -h' and 'ps aux'
    while (1) {
        sleep(1);
    }

    return 0;
}


================================================================================
>>> Experiment 9 (CPU-Bound): Computational Intensive Process
>>> Source File: Experiment 9/cpu.c (C Program (cpu.c))
================================================================================

#include <stdio.h>

/*
 * Experiment 9: CPU-Bound Process
 * Executes an intensive compute loop to continuously consume CPU cycles.
 * Observed via 'top' consuming ~100% CPU.
 */

int main()
{
    printf("CPU-bound process started. Consuming CPU cycles...\n");
    volatile unsigned long long counter = 0;
    while (1) {
        counter++;
    }
    return 0;
}


================================================================================
>>> Experiment 9 (I/O-Bound): Sleeping/Waiting Process
>>> Source File: Experiment 9/io.c (C Program (io.c))
================================================================================

#include <stdio.h>
#include <unistd.h>

/*
 * Experiment 9: I/O-Bound Process
 * Spends most of its time in sleeping / waiting state.
 * Observed via 'top' consuming negligible CPU (< 1%) and via 'pmap' for memory mapping.
 */

int main()
{
    printf("I/O-bound process started. Sleeping in loop...\n");
    while (1) {
        sleep(1);
    }
    return 0;
}


================================================================================
>>> Experiment 9 (Monitor): Process Monitoring and Memory Mapping Script
>>> Source File: Experiment 9/exp9_monitor.sh (Bash Benchmark Script (exp9_monitor.sh))
================================================================================

#!/bin/bash
# ==============================================================================
# Experiment 9: CPU-Bound vs I/O-Bound Process Execution & Monitoring
# Compiles cpu.c and io.c, executes both in background, and demonstrates
# monitoring with 'top' and memory mapping inspection with 'pmap -x'.
# ==============================================================================

echo "======================================================"
echo "Experiment 9: CPU vs I/O Bound Process Benchmark"
echo "======================================================"

# 1. Compile C programs
gcc cpu.c -o cpu
gcc io.c -o io

# 2. Launch CPU-bound process in background
./cpu &
CPU_PID=$!
echo "CPU-bound process started with PID: $CPU_PID"

# 3. Launch I/O-bound process in background
./io &
IO_PID=$!
echo "I/O-bound process started with PID: $IO_PID"

echo -e "\nAllowing processes to stabilize for 3 seconds..."
sleep 3

echo -e "\n[1] Process status from 'ps aux':"
ps aux | grep -E "$CPU_PID|$IO_PID" | grep -v grep

echo -e "\n[2] Virtual Memory mapping for CPU-bound process (PID: $CPU_PID):"
pmap -x $CPU_PID | head -n 15

echo -e "\n[3] Virtual Memory mapping for I/O-bound process (PID: $IO_PID):"
pmap -x $IO_PID | head -n 15

# Clean-up
echo -e "\nTerminating test processes..."
kill $CPU_PID $IO_PID
echo "Killed PID $CPU_PID and PID $IO_PID."


================================================================================
>>> Experiment 10: Process Creation & Synchronization with fork() & wait()
>>> Source File: Experiment 10/exp10.c (C Program (exp10.c))
================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * Experiment 10: Process Creation and Management using System Calls
 * Uses fork() to create a child process, getpid() to report PIDs,
 * and wait(NULL) in the parent process to synchronize execution.
 */

int main()
{
    pid_t p = fork();

    if (p < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }

    if (p == 0)
    {
        // Child Process
        printf("Child PID: %d\n", getpid());
        printf("Child process is running\n");
        sleep(2);
        printf("Child process terminated\n");
        exit(0);
    }
    else
    {
        // Parent Process
        printf("Parent PID: %d\n", getpid());
        wait(NULL); // Wait for child process to terminate
    }

    return 0;
}












=====================================
(function () {

    // Remove inline handlers
    document.querySelectorAll('*').forEach(el => {
        [
            'oncopy','onpaste','oncut','oncontextmenu',
            'onselectstart','ondragstart','onmousedown',
            'onmouseup','onkeydown','onkeypress'
        ].forEach(attr => el[attr] = null);

        el.removeAttribute('disabled');
        el.removeAttribute('readonly');
        el.style.userSelect = 'text';
        el.style.webkitUserSelect = 'text';
    });

    // Kill event blockers
    [
        'copy','paste','cut','contextmenu',
        'selectstart','dragstart',
        'keydown','keypress','mousedown'
    ].forEach(evt => {
        window.addEventListener(evt, e => {
            e.stopImmediatePropagation();
        }, true);
    });

    // Enable content editing
    document.body.contentEditable = true;

    // Force selectable text
    const style = document.createElement('style');
    style.innerHTML = `
        * {
            user-select: text !important;
            -webkit-user-select: text !important;
        }
    `;
    document.head.appendChild(style);

    console.log("Maximum restrictions removed");

})();
====================================
