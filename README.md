# Qt Text Editor with Keyboard Shortcuts

This is a simple text editor application built using the Qt framework in C++. It allows users to open, edit, and save text files with keyboard shortcuts for quick access to common actions. The application provides basic functionality for loading and saving text files.

## Features
- **New File (Ctrl+N):** Opens a file dialog for creating a new `.txt` file.
- **Open File (Ctrl+O):** Opens a file dialog for selecting a `.txt` file to load its content into the text editor for editing or reading.
- **Save File (Ctrl+S):** Opens a file dialog to save the current text in the editor to a file.
- **Find (Ctrl+F):** Enter a word or phrase to search and all matches will be highlighted.
- **Exit:** Closes the application through the menu option or using the window's close button.

## Files and Structure
### Code Structure
- `mainwindow.h`: Header file for the `MainWindow` class.
- `mainwindow.cpp`: Implementation file for the main window, handling UI and functionality for opening, saving, and exiting.
- `finddialog.h`: Header file for the `FindDialog` class.
- `finddialog.cpp`: Implementation file for the 'FIND' functionality, handling UI and highlighting.

### Dependencies
- Qt framework (e.g., Qt 5 or Qt 6) with widgets support.
- C++ compiler compatible with Qt.

## How to Run
1. **Install Qt**  
   Ensure you have Qt installed (download from [Qt Downloads](https://www.qt.io/download)) and a compatible C++ compiler (e.g., MinGW, MSVC).

2. **Build the Project**  
   Open the project in **Qt Creator** or build it manually using `qmake`:
   ```bash
   qmake
   make
   ```

3. **Run the Application**  
   Launch the application using the generated executable.

## Known Limitations
- Only supports text files with `.txt` extensions.
- Basic error handling is implemented for file operations.
- The editor currently does not track unsaved changes before exiting.
