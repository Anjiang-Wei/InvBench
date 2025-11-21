# InvBench: Can LLMs Accelerate Program Verification with Invariant Synthesis?

InvBench is the official repository for the paper "Can LLMs Accelerate Program Verification with Invariant Synthesis?". 

## Repository Structure

```
InvBench/
├─ Dataset/
│  ├─ Evaluation/
│  │  ├─ Easy/               # 113 C programs (Easy Split)
│  │  ├─ Hard/               # 113 C programs (Hard Split)
│  │  └─ timing.json         # Evaluation timing data
│  └─ Training/
│     ├─ Programs/           # 3589 C programs for training
│     ├─ invariants.json     # Ground-truth invariants for training programs
│     └─ timing.json         # Training timing data
```

## Dataset

- Easy Split: 113 C programs under `Dataset/Evaluation/Easy/`.
- Hard Split: 113 C programs under `Dataset/Evaluation/Hard/`.
- Training Programs: 3589 C programs under `Dataset/Training/Programs/`.
- Ground-truth Invariants: `Dataset/Training/invariants.json`.
- Timing Data: `Dataset/Evaluation/timing.json` and `Dataset/Training/timing.json`. Each `time` value records the time that UAutomizer takes to solve the corresponding program.

## License

This project is licensed under the [Apache License 2.0](https://opensource.org/license/apache-2-0). 
