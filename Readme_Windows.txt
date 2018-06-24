CPP Projects Read-me (Windows)


As a prerequisite, you need to install CMake. Download it from here:
https://cmake.org/download/ and install it accordingly. 


Step 1: Unzipping
- Unzip CPP-BaseProject.zip into a new folder


Step 2: CMake Configuration
- Start CMake GUI and select the newly created unzip folder as the SOURCE CODE directory
- Create a second build folder and select it as the BUILD BINARIES directory 
- Press CONFIGURE BUTTON to select the desired generator --> Visual Studio 15 2017 Win64
- Check for any configure errors (in red) and solve them :-)
- Press GENERATE BUTTON to generate the selected build environment code
- If needed, you can change some CMake define values (in red) (usually not necessary)
- Press GENERATE BUTTON once again until all CMake define values turn black


Step 3: Visual Studio Build
- Open Visual Studio solution file (CPP_Projects.sln), either by navigating to the
  BUILD BINARIES directory or by pressing the OPEN PROJECT BUTTON in the CMake GUI
- In Visual Studio use BUILD SOLUTION MENU to build all CPP sub-projects
- To build/start just a single project, select SET AS STARTUP PROJECT MENU from the right
  mouse button pop-up menu.