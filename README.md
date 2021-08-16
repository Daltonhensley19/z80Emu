
<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>




## About The Project


Hello, all! Emulating the Zilog Z80 has been nothing short of a purely academic venture. However, I would be lying to you if I were to say that I did not have fun along the way. More to the point--the Z80 is the perfect project to enrich your understanding of lower-level system's programming magic. While not for everyone, it does have its benefits™:

The benefits™:
* Learn how to reason about the interconnected processes between the CPU and RAM.
* As the emulator matures, you come to better understand gaps in your knowledge. Not sure how ISA's work? Learn by building one. As an example: the Z80 instruction set. 
* Finally, if you are anything like me, you will become obsessed with reading manuals and documentation that are decades old in the pursuit of unlocking the underlying mechanisms behind your target emulator.  

Of course, no one system can adequately entrench a full understanding of computer architecture in its entirety, but also that would sorely be missing the point. Emulator dev is a journey, not a destination. It is, therefore, important that one takes in the scenery. 

A list of commonly used resources that I find helpful are listed in the acknowledgements.

### Built With

* [CMake](https://cmake.org/download/)
* [C++](https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0)
* [GCC](https://gcc.gnu.org/install/download.html)




## Getting Started

This is an example of how you may give instructions on setting up the project locally.
To get a local copy up and running, follow these simple example steps.

### Prerequisites using an Arch Based Linux Distro

You will nedd to install CMake, GCC, GLFW, and OpenGL.
* CMake
  ```sh
  sudo pacman -S cmake
  ```
* GCC
  ```sh
  sudo pacman -S gcc
  ```
* GLFW and OpenGl
  ```sh
  sudo pacman -S glfw gl
  ```
### Installation
1. Clone the repo
   ```sh
   git clone https://github.com/Daltonhensley19/z80Emu2.git
   ```
2. Make a build directory
   ```sh
   cd z80Emu2 && mkdir build 
   ```
3. Generate Makefiles using CMake
   ```sh
   cd build && cmake ..
   ```
3. Build project 
   ```sh
   make
   ```



## Usage

Z80Emu2 works in a rather simple way.

*Run the program inside the `build` directory using this command.
   ```sh
   z80Emu2 ../memory_test.bin
   ```
## License

Distributed under the MIT License. See `LICENSE` for more information.




## Contact

Dalton Hensley -  dzhensley@moreheadstate.edu


