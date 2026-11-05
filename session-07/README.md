# Session 07 — CMake and Git

A supplied starting point, not a completed exercise. All tasks use only this session’s files.

## What you will learn

Write a minimal CMake project; distinguish configure/build/run; inspect, commit, and undo a small change using the Git workflow agreed in class.

## Tasks

1. Build the supplied project. Explain minimum version, project, executable target, and its source list.
2. In a new folder, recreate this small project and CMakeLists.txt. Build it in a fresh build directory.
3. Build again without editing; observe no recompilation. Edit source/Tempo.cpp and rebuild; only Tempo.cpp is recompiled. Then edit the message in source/Tempo.h and rebuild; both .cpp files are recompiled because both include that header. The #pragma message lines show which files are processed.
4. In the Git repository you are using for the course, run git status and git diff. Make a baseline commit before editing the session. If Git asks, configure your author name/email for this repository.
5. Change only the printed label. Inspect the diff, build/run, and either commit or discard just that change.

## Check your result

### Git command reference

Run these from the Git repository you are using for the course. Follow the workflow agreed in class; this may be a personal repository or a branch in the course repository. Before committing, add `build/`, `build-*/`, and generated executables to `.gitignore`.

If author details are missing, set them for this repository using your own values:

```bash
git config user.name "Your Name"
git config user.email "your-chosen-email@example.com"
```

From the session folder, create a baseline before editing:

```bash
git status
git add CMakeLists.txt source/main.cpp source/Tempo.h source/Tempo.cpp
git commit -m "Save session 7 baseline"
```

After an edit, inspect `git diff -- source/main.cpp`. To keep it, add the file and commit again. To discard only that uncommitted edit, use `git restore -- source/main.cpp` **after confirming the diff is disposable**. Do not run restore on work you want to keep. No remote or push is needed for this exercise.

A clean configure/build succeeds; no-edit rebuild does not recompile; only the requested label changes. The baseline commit allows recovery.

## Individual checkpoint

Explain CMake versus compiler versus build tool. Show a diff and explain each changed line.

## Optional extension

Add one additional source file explicitly to the target, without file globbing.

## Practice after class

Add `twoBeatsMs(double bpm)` to `Tempo.h` and `Tempo.cpp`, and call it from `main.cpp`. Build, then change only its implementation in `Tempo.cpp` and rebuild. Note which source is recompiled and explain why `main.cpp` does not need recompiling.

## Build and run

Open **this session folder** in VS Code, not the course root. Save your changes in this session folder and follow the Git workflow agreed in class. Complete [setup](../setup/README.md) first. These are supplied build commands until session 7 explains CMake.

Configure on macOS/Linux:

```bash
cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
```

Configure on Windows (VS Code launched from a Developer Command Prompt):

```powershell
cmake -S . -B build -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug
```

Build on all platforms:

```bash
cmake --build build
```

Run on macOS/Linux: `./build/bin/main`. On Windows: `.\build\bin\main.exe`.

Run only after a successful build. If you move the project, use a fresh build directory. For lesson 5 onwards, select **Lesson — your platform** in Run and Debug, then F5; the supplied task builds before launch. Save changes first. C++/debugger extensions are described in the setup sheet.
