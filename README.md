# FilmTech: Production Office Automation

FilmTech is a C++ command-line application for organizing production logistics:
scenes, locations, and dialogue into a structured plan. The design favors
offline operation, deterministic behavior, and minimal dependencies.

## Current Capabilities

* Core production data model: `Scene`, `Location`, `Line`, `Role`
* In-memory plan construction (sample data)
* Console output: scene -> location -> time -> lines

## Planned Capabilities

* Parse structured inputs (text and/or FDX)
* Scheduling and validation
* Optional constraint-based scheduling
* Call sheet/report generation

## Requirements

* Apple clang 15+
* CMake 3.24+
* Ninja 1.11+

Verify:

```bash
clang++ --version
cmake --version
ninja --version
```

## Build

From repo root:

```bash
cmake --preset dev
cmake --build --preset dev
```

## Run

```bash
./build/dev/filmtech
```

## VS Code (Optional)

Recommended extensions:

* C/C++ (Microsoft)
* CMake Tools
* CMake

If the repo includes `.vscode/` configuration, open the folder in VS Code and
use CMake Tools to configure/build with the `dev` preset.

## Repo Layout

```text
.
├── CMakeLists.txt
├── CMakePresets.json
├── src/
│   └── main.cpp
├── include/
├── tests/
├── .vscode/
└── build/        (generated; do not commit)
```

## Notes

* `build/` is generated output and should not be committed.
* Source lives in `src/`; headers live in `include/`.
