# InvBench: Can LLMs Accelerate Program Verification with Invariant Synthesis?

[![arXiv](https://img.shields.io/badge/arXiv-2509.21629-b31b1b.svg)](https://www.arxiv.org/abs/2509.21629) [![License](https://img.shields.io/badge/License-Apache%202.0-brightgreen.svg)](https://opensource.org/license/apache-2-0) 

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

## Citation

If our research inspires you, please cite our paper:

```bibtex
@misc{wei2025invbenchllmsaccelerateprogram,
    title={InvBench: Can LLMs Accelerate Program Verification with Invariant Synthesis?}, 
    author={Anjiang Wei and Tarun Suresh and Tianran Sun and Haoze Wu and Ke Wang and Alex Aiken},
    year={2025},
    eprint={2509.21629},
    archivePrefix={arXiv},
    primaryClass={cs.PL},
    url={https://arxiv.org/abs/2509.21629}, 
}
```

## License

This project is licensed under the [Apache License 2.0](https://opensource.org/license/apache-2-0). 
