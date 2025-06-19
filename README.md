🏥 Hospital Management System in C

This is a simple Hospital Management System developed in the C programming language.
It runs in the terminal and allows basic operations like adding, viewing, searching, 
and deleting patient records. Data is stored persistently in a text file (patients.txt).

------------------------------------------------------------
📌 Features

- Add a new patient
- Display all patient records
- Search patient by ID
- Delete a patient record
- Persistent file storage using patients.txt

------------------------------------------------------------
📁 File Structure

Hospital-Management-System/
├── hospital.c        - C source code
├── patients.txt      - Auto-created file for storing patient records
└── README.txt        - This documentation

------------------------------------------------------------
🧑‍💻 Sample Program Output

Hospital Management System
1. Add Patient
2. View Patients
3. Search Patient
4. Delete Patient
5. Exit
Enter your choice: 1

Enter Patient ID: 13
Enter Name: Ahamed
Enter Age: 21
Enter Disease: pneumonia
Patient added successfully!

Enter your choice: 2

--- Patient List ---
ID: 13, Name: Ahamed, Age: 21, Disease: pneumonia

------------------------------------------------------------
🧰 Installation Guide (Windows - Using MinGW)

1. Download MinGW
   - Visit: https://sourceforge.net/projects/mingw-w64/
   - Download and install mingw-w64-install.exe

2. Install GCC with MinGW
   - Architecture: x86_64
   - Threads: posix
   - Exception: seh
   - Install to: C:\MinGW (or another folder)

3. Add MinGW to PATH
   - Right-click This PC → Properties
   - Advanced system settings → Environment Variables
   - Edit the 'Path' variable under System Variables
   - Add: C:\MinGW\bin

4. Verify Installation
   - Open Command Prompt
   - Type: gcc --version

------------------------------------------------------------
⚙️ Compile and Run the Program

1. Save your C code in hospital.c
2. Open Command Prompt
3. Navigate to your folder:
   cd C:\path\to\your\project

4. Compile:
   gcc hospital.c -o hospital.exe

5. Run:
   hospital.exe

------------------------------------------------------------
💡 Notes

- Patient records are stored in patients.txt
- File is created automatically if not found
- IDs must be numeric
- Supports names/diseases with spaces
- No duplicate ID validation in current version

------------------------------------------------------------
🔓 License

This project is released under the MIT License.
You are free to use, modify, and share it for educational purposes.

------------------------------------------------------------
🙋‍♂️ Author

Name: Ahamed
Email: ahamedibrahiminfo@gmail.com

Feel free to contribute, suggest improvements, or fork the project!
