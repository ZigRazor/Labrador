# Labrador

<img style="float: right;" align="left" src="https://images.unsplash.com/photo-1588022274642-f238f77ec193?q=80&w=2671&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D" width="200">

C++ Queue Elaboration Framework

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE) [![GitHub release](https://img.shields.io/github/release/ZigRazor/Labrador.svg)](https://GitHub.com/ZigRazor/Labrador/releases/) [![CMake](https://github.com/ZigRazor/Labrador/actions/workflows/cmake.yml/badge.svg)](https://github.com/ZigRazor/Labrador/actions/workflows/cmake.yml) 

[![codecov](https://codecov.io/gh/ZigRazor/Labrador/graph/badge.svg?token=24SM5HBW6C)](https://codecov.io/gh/ZigRazor/Labrador) [![CodeFactor](https://www.codefactor.io/repository/github/zigrazor/labrador/badge)](https://www.codefactor.io/repository/github/zigrazor/labrador)

[![Generic badge](https://img.shields.io/badge/required-C++20-Green.svg)](https://shields.io/) [![Generic badge](https://img.shields.io/badge/Required-CMake3.16-Green.svg)](https://shields.io/)

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)
- [Acknowledgements](#acknowledgements)

## Description

Labrador is a C++ Queue library. This project aims to fulfill a framework for concurrent queue elaboration. By using Labrador, users can:
- Create queues of different type ( ex. Bounded, Lock-wait, Concurrent )
- Craete more sophisticated application that use queue processor to process in a simple way the enqueued items.

## Features

- Concurrent Queue
- Boundend Queue
- Lock-Wait Bounded Queue
- Queue Processor
- Asynchronous Queue Processor

## Installation

To install and set up Labrador, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ZigRazor/Labrador.git
   ```
2. **Navigate to the project directory:**
  ```bash
  cd Labrador
  ```
3. **Prepare CMake:**
  ```bash
  mkdir build
  cd build
  cmake ..
 ```
4. **Install Library**
   ```bash
   make install
   ```
     
## Usage

You can use the Library in your project with CMake adding the following lines:

```cmake
CPMAddPackage(
    NAME Labrador
    GITHUB_REPOSITORY ZigRazor/Labrador
    GIT_TAG origin/main
)
```
or install it and the add to the include path *{StandardIncludePath}/DogBreeds/Labrador*. 

For simple use you can see the [Example](https://github.com/ZigRazor/Labrador/tree/main/example)
For more detailed usage instructions, refer to the documentation.

## Contributing
We welcome contributions to Labrador! To contribute, follow these steps:

1. **Fork the repository.**
2. **Create a new branch:**
  ```bash
  git checkout -b feature/your-feature-name
  ```
3. **Make your changes and commit them:**
  ```bash
  git commit -m "Add your commit message"
  ```
4. **Push to the branch:**
  ```bash
  git push origin feature/your-feature-name
  ```
5. **Create a pull request.**

Please read our [contributing guidelines](https://github.com/ZigRazor/Labrador/blob/main/CONTRIBUTING.md) for more details.

## License
This project is licensed under the MIT License. See the [LICENSE](https://github.com/ZigRazor/Labrador/blob/main/LICENSE) file for details.

## Contact
If you have any questions, suggestions, or feedback, feel free to reach out:

- Email: zigrazor@gmail.com
- GitHub Issues: [issues](https://github.com/ZigRazor/Labrador/issues)

## Acknowledgements
We would like to thank the following individuals for their support:

[![Contributors](https://contrib.rocks/image?repo=zigrazor/Labrador)](https://github.com/ZigRazor/Labrador/graphs/contributors) 
