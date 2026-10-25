# Online Job Portal (C++)

A menu-driven, console-based **Online Job Portal** developed in C++. The
project demonstrates job-seeking and recruitment activities using
functions, menus, and local file handling.

## Features

-   User registration and login
-   Admin login and user management
-   Post, view, search, and delete jobs
-   Apply for jobs and view applications
-   Update application status and view status notifications
-   Search applicants and filter applications by status or company
-   Manage company records
-   Upload, list, and open resumes
-   Save jobs and view job recommendations
-   Schedule, view, search, update, and delete interviews
-   Generate reports and export jobs/interviews to CSV
-   View application receipts

## Technology Stack

-   **Language:** C++
-   **IDE/Compiler:** Dev-C++ or a compatible C++ compiler
-   **Platform:** Windows
-   **Storage:** Local text files

## Getting Started

### Prerequisites

-   Windows computer
-   Dev-C++ or another compatible C++ compiler
-   Project source file: `main.cpp`

### Run in Dev-C++

1.  Open Dev-C++.
2.  Open `main.cpp` or create a C++ project and add the source file.
3.  Keep the source and any supporting files in the project folder.
4.  Compile and run the program (commonly **F11** in Dev-C++).
5.  Follow the numbered menu in the console and enter the option number
    for the operation you want.

> **Note:** The program uses local data files. Run it from a consistent
> working directory so records are created and found in the expected
> location.

## Data Files

The program uses local text files. Depending on the features used, files
may include:

-   `users.txt` --- user records
-   `jobs.txt` --- job records
-   `applications.txt` --- application records
-   `notifications.txt` --- application-status notifications

Other files may be used for companies, resumes, saved jobs, interviews,
receipts, reports, or exports.

## Application Status Notifications

When an application status is updated, the program can append a message
to `notifications.txt`. Applicants can select the notification option
and enter their name to view matching notifications.

## Project Structure

``` text
Online-Job-Portal/
├── main.cpp
├── README.md
└── local data files created while using the program
```

## Testing Checklist

-   [ ] Register a user and test login.
-   [ ] Post a job and confirm it appears in the job list.
-   [ ] Search for a job and apply.
-   [ ] Update the application status.
-   [ ] View notifications for the applicant.
-   [ ] Test resume and interview functions.
-   [ ] Generate a report or export data to CSV.
-   [ ] Verify that the program exits correctly.

## Limitations

-   This is a local console-based academic project, not a deployed
    website.
-   Text-file storage is intended for demonstration and is not a
    production database.
-   Security, validation, and multi-user access would need improvement
    before real-world deployment.

## Future Enhancements

-   Add a database such as SQLite or MySQL.
-   Build a graphical or web-based interface.
-   Strengthen authentication and role-based access control.
-   Add email notifications and advanced job filters.
-   Improve validation, automated testing, and reporting.

## Author

**Mausam Chaturvedi**

## Academic Details

-   **Course:** MCA, First Semester
-   **Roll Number:** 26MCA20182
-   **Institute:** University Institute of Computing (UIC), Chandigarh
    University
-   **Project Guide:** Ms. Ashima Sood
-   **Session:** 2026--27

## License

No license has been specified. Add a license file if you want others to
reuse, modify, or distribute this project.
