## Date Estructure

### Guide to install gcc for c and c++ in Windows

1. Download the MinGW-w64 installer from the following link: [MinGW](https://sourceforge.net/projects/mingw/files/latest/download)

2. Install MinGW-w64

the installer will guide you through the installation process and prompt you to select the components you want to install.

3. Select Packges Required for the Compiler.

- mingw32-base : You have to install this package, it contains the basic tools for the compiler.
- mingw32-gcc-g++ : This package contains the C++ compiler, if you want to compile C++ programs, you have to install this package.
- mingw32-gcc-objc: This package contains the Objective-C compiler, if you want to compile Objective-C programs, you have to install this package.

4. Apply the changes.

After selecting all the required packages, go to installation >> Apply Changes and click on Apply.

5. Download the Changes.

After clicking on Apply, the installer will download and install all the selected packages.

6. Add MinGW-w64 to the System Path.

To use the MinGW-w64 tools from the command line, you have to add the bin directory of your MinGW-w64 installation to the system path.

When you install MinGW-w64, it creates a folder named MinGW in the C:\ drive. Inside the MinGW folder, there is a folder named bin that contains the executables of the MinGW-w64 tools. To set the compiler's path, we need to path the bin directory of the MinGW-w64 installation to the system path.

7. Setting the Environment Variables.

- Open the start menu and search for "Environment Variables" and click on "Edit the system environment variables".

- In the System Properties window, click on the "Environment Variables".

- In the Environment Variables window, under the System variables section, select the "Path" variable and click on the "Edit" button.

- In the Edit Environment Variable window, click on the "New" button and add the path to the bin directory of your MinGW-w64 installation.

- Click on the "OK" button to close the Edit Environment Variable window.

- Click on the "OK" button to close the Environment Variables window.

- Click on the "OK" button to close the System Properties window.

8. Verify the Installation.

To verify the installation, open the command prompt and type the following command:

```bash
gcc --version
```

If the installation was successful, you will see the version of the GCC compiler.


8. Issues on vscode.

if the erros is something like this:

#include errors detected. Please update your includePath. Squiggles are disabled for this translation unit (C:\Users\DEPLAN\Documents\ed-especial\atividade-A\q1.c).C/C++(1696)
cannot open source file "stdio.h". Please run the 'Select IntelliSense Configuration...' command to locate your system headers

solution:

- Open the command palette (Ctrl+Shift+P) and type "C/C++:Select IntelliSense Configuration"
- Select "mingw32" from the list of configurations.

