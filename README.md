# DSA01 – Assignment 4: Designing Reusable Class Hierarchies

**Name:** [Enter your name]  
**Register Number:** 192524372  
**Course:** Object Oriented Programming with C++ (DSA01)  
**Compiler:** g++ (record the version installed on your computer)  
**Standard:** C++17

## Folder structure

- `Task01/` – payroll hierarchy and alternative switch-based design
- `Task02/` – university people hierarchy, virtual diamond and access table
- `Task03/` – base/member construction and destruction order; completed TODO 1
- `Task04/` – runtime polymorphism, virtual destructor, slicing and smart pointers
- `Task05/` – object pointers, references, `this`, method chaining and maximum cart
- `Task06/` – extensible vehicle-rental hierarchy and demonstration

Each task contains a standalone `.cpp` program and a text file with a sample run. Compile and run each program yourself on your computer and replace/confirm sample output with your actual output. The assignment also asks for output screenshots, prediction-before-execution evidence, a written report, and sanitizer evidence; these must be completed from your own execution and submitted as required by your faculty.

## Compile and run (PowerShell terminal in VS Code)

Open this folder in VS Code. For example, from the folder containing it:

```powershell
cd .\DSA01-192524372-Assignment4
g++ --version
g++ -std=c++17 -Wall -Wextra Task01\main.cpp -o Task01\main.exe
.\Task01\main.exe
```

Repeat for each task, changing the task folder:

```powershell
g++ -std=c++17 -Wall -Wextra Task02\main.cpp -o Task02\main.exe
.\Task02\main.exe

g++ -std=c++17 -Wall -Wextra Task03\main.cpp -o Task03\main.exe
.\Task03\main.exe

g++ -std=c++17 -Wall -Wextra Task04\main.cpp -o Task04\main.exe
.\Task04\main.exe

g++ -std=c++17 -Wall -Wextra Task05\main.cpp -o Task05\main.exe
.\Task05\main.exe

g++ -std=c++17 -Wall -Wextra Task06\main.cpp -o Task06\main.exe
.\Task06\main.exe
```

For AddressSanitizer where your compiler supports it:

```powershell
g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer Task04\main.cpp -o Task04\account_asan.exe
.\Task04\account_asan.exe
```

## GitHub repository creation and upload

The assignment specifies the repository name `DSA01-<RegisterNumber>-Assignment4`. For register number `192524372`, create:

`DSA01-192524372-Assignment4`

1. Sign in at https://github.com.
2. Click **New repository**.
3. Enter `DSA01-192524372-Assignment4`.
4. Choose Public, or choose Private and add your faculty as a collaborator.
5. Do not initialize the repository with a README if you plan to push this existing folder.
6. In VS Code, open this extracted project folder and open **Terminal → New Terminal**.
7. Run the commands below. Replace the URL with the exact HTTPS URL shown on your new GitHub repository page.

```powershell
git init
git branch -M main
git add .
git commit -m "Add Task 1: payroll class hierarchy"
git remote add origin https://github.com/YOUR-USERNAME/DSA01-192524372-Assignment4.git
git push -u origin main
```

The assignment requires progressive commits, at least one per task. After the first push, make a separate commit for each task (do not make only one final commit). If you prefer to meet that requirement clearly, use this sequence before the first push instead of `git add .`:

```powershell
git init
git branch -M main
git add Task01
git commit -m "Add Task 1: payroll class hierarchy"
git add Task02
git commit -m "Add Task 2: university people hierarchy"
git add Task03
git commit -m "Add Task 3: constructors and member classes"
git add Task04
git commit -m "Add Task 4: polymorphic account pointers"
git add Task05
git commit -m "Add Task 5: object pointers and this pointer"
git add Task06
git commit -m "Add Task 6: vehicle rental hierarchy"
git add README.md
git commit -m "Add project instructions"
git remote add origin https://github.com/YOUR-USERNAME/DSA01-192524372-Assignment4.git
git push -u origin main
```

After pushing, refresh the repository page and copy its URL into the assignment cover page.

## Important before submission

- Confirm your name and register number.
- Run every `.cpp` file using the exact compiler command.
- Capture your own terminal output screenshots and place them in the corresponding task folder (for example `Task01/output-screenshot.png`).
- Write each required output prediction **before** running the relevant prediction program, then record the actual result and explain any differences.
- Complete the written analysis, UML diagram, access table, pseudocode and complexity comparisons in your report. Code alone does not replace these written requirements.
- The sample output files are reference guides, not proof that you personally executed the programs.
