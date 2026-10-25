#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>

using namespace std;

class User
{
public:
    string name;
    string email;
    string password;
    string phone;
    string qualification;
    string skills;
};

class Job
{
public:
    int jobID;
    string companyName;
    string jobTitle;
    string salary;
    string skills;
    string category;
};

class Application
{
public:
    string applicantName;
    string companyName;
    string jobTitle;
    string status;
};

class Interview
{
public:
    string applicantName;
    string companyName;
    string jobTitle;
    string date;
    string time;
};


class Admin
{
public:
    string username;
    string password;
};

class Company
{
public:
    string companyName;
    string location;
};


// Function Prototypes
void viewApplicationNotifications();
void deleteApplicationReceipt();
void viewApplicationReceipt();
void withdrawApplication();
void viewMyApplications();
void searchApplicationsByCompany();
void viewApplicationsByStatus();
void applicationStatusReport();
void exportInterviewsToCSV();
void exportJobsToCSV();
void searchInterview();
void updateInterview();
void deleteInterview();
void generateReport();
void scheduleInterview();
void viewInterviews();
void recommendJobs();
void saveJob();
void viewSavedJobs();
void openResumeFromApplication();
void openResume();
void uploadResume();
void viewResumes();
void addCompany();
void viewCompanies();
void deleteCompany();
void setColor(int color);
string getPassword();
void changePassword();
void editProfile();


// User Registration Function
void registerUser()
{
   User user;

    cout<<"\n===== USER REGISTRATION =====\n";

    cout<<"Enter Name: ";
    cin>>user.name;

    cout<<"Enter Email: ";
    cin>>user.email;

    cout<<"Enter Password: ";
    user.password = getPassword();

    cout<<"Enter Phone: ";
    cin>>user.phone;

    cout<<"Enter Qualification: ";
    cin>>user.qualification;

    cout<<"Enter Skills: ";
    cin>>user.skills;

    ofstream file("users.txt", ios::app);

    file << user.name << "|"
     << user.email << "|"
     << user.password << "|"
     << user.phone << "|"
     << user.qualification << "|"
     << user.skills << endl;

    file.close();

    cout<<"\nRegistration Successful!\n";
}

// User Login Function
void loginUser()
{
    string email,password;
    string line;

    cout<<"\n===== USER LOGIN =====\n";

    cout<<"Enter Email: ";
    cin>>email;

    cout<<"Enter Password: ";
    cin>>email;
password = getPassword();

    ifstream file("users.txt");

    bool found = false;

    while(getline(file,line))
    {
        if(line.find(email) != string::npos &&
           line.find(password) != string::npos)
        {
            found = true;
            break;
        }
    }

    file.close();

   if(found)
{
    setColor(10);
    cout<<"\nLogin Successful!\n";
    setColor(7);
}
   else
{
    setColor(12);
    cout<<"\nInvalid Email or Password!\n";
    setColor(7);
}
}


void postJob()
{
    Job job;

    cout<<"\n===== POST JOB =====\n";

    cout<<"Enter Job ID: ";
    cin>>job.jobID;

    cin.ignore();

    cout<<"Enter Company Name: ";
    getline(cin,job.companyName);

    cout<<"Enter Job Title: ";
    getline(cin,job.jobTitle);

    cout<<"Enter Salary: ";
    getline(cin,job.salary);

    cout<<"Enter Required Skills: ";
    getline(cin,job.skills);
    cout<<"Enter Category (IT/HR/Finance): ";
    getline(cin,job.category);

    ofstream file("jobs.txt",ios::app);

    file<<job.jobID<<"|"
    <<job.companyName<<"|"
    <<job.jobTitle<<"|"
    <<job.salary<<"|"
    <<job.skills<<"|"
    <<job.category<<endl;

    file.close();

    cout<<"\nJob Posted Successfully!\n";
}


void viewJobs()
{
    string line;

    ifstream file("jobs.txt");

    cout<<"\n========================================================";
    cout<<"\n                    AVAILABLE JOBS";
    cout<<"\n========================================================\n";

    while(getline(file,line))
    {
        cout<<"--------------------------------------------------\n";
        cout<<line<<endl;
        cout<<"--------------------------------------------------\n";
    }

    file.close();
}




void applyJob()
{
    Application app;
    string line;
    bool duplicate = false;

    cout << "\n===== APPLY FOR JOB =====\n";

    cin.ignore();

    cout << "Enter Your Name: ";
    getline(cin, app.applicantName);

    cout << "Enter Company Name: ";
    getline(cin, app.companyName);

    cout << "Enter Job Title: ";
    getline(cin, app.jobTitle);

    // Check for duplicate applications
    ifstream infile("applications.txt");

    if (!infile)
    {
        cout << "\nUnable to open applications.txt!\n";
        return;
    }

    while (getline(infile, line))
    {
        size_t p1 = line.find('|');
        size_t p2 = string::npos;
        size_t p3 = string::npos;

        if (p1 != string::npos)
            p2 = line.find('|', p1 + 1);

        if (p2 != string::npos)
            p3 = line.find('|', p2 + 1);

        if (p1 != string::npos &&
            p2 != string::npos &&
            p3 != string::npos)
        {
            string existingName = line.substr(0, p1);
            string existingCompany =
                line.substr(p1 + 1, p2 - p1 - 1);
            string existingJob =
                line.substr(p2 + 1, p3 - p2 - 1);

            if (existingName == app.applicantName &&
                existingCompany == app.companyName &&
                existingJob == app.jobTitle)
            {
                duplicate = true;
                break;
            }
        }
    }

    infile.close();

    if (duplicate)
    {
        cout << "\nYou have already applied for this job!\n";
        return;
    }

    app.status = "Applied";

    // Save application details
    ofstream file("applications.txt", ios::out | ios::app);

    if (!file)
    {
        cout << "\nUnable to save application!\n";
        return;
    }

    file << app.applicantName << "|"
         << app.companyName << "|"
         << app.jobTitle << "|"
         << app.status << endl;

    file.close();

    // Save receipt in APPEND mode

    // Append receipt to the existing file
    ofstream receipt("application_receipt.txt", ios::app);

    if (!receipt.is_open())
    {
        cout << "\nUnable to open receipt file!\n";
        return;
    }

    receipt << "\n====================================\n";
    receipt << "       JOB APPLICATION RECEIPT\n";
    receipt << "====================================\n";
    receipt << "Applicant Name: " << app.applicantName << endl;
    receipt << "Company Name: " << app.companyName << endl;
    receipt << "Job Title: " << app.jobTitle << endl;
    receipt << "Status: " << app.status << endl;
    receipt << "====================================\n";

    receipt.close();

    cout << "\nReceipt saved successfully!\n";


    // Display all saved receipts
    ifstream checkFile("C:\\Users\\hp\\Desktop\\Online Job Portal - C++\\application_receipt.txt");

    if (!checkFile)
    {
        cout << "\nUnable to read receipt file!\n";
        return;
    }

    string receiptLine;

    cout << "\n===== ALL SAVED RECEIPTS =====\n";

    while (getline(checkFile, receiptLine))
    {
        cout << receiptLine << endl;
    }

    checkFile.close();

    cout << "\nApplication Submitted Successfully!\n";
    cout << "Company: " << app.companyName << endl;
    cout << "Job Title: " << app.jobTitle << endl;
    cout << "Status: " << app.status << endl;
    cout << "Receipt added successfully!\n";
}






void viewApplications()
{
    string line;

    ifstream file("applications.txt");

    cout<<"\n===== JOB APPLICATIONS =====\n\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}


void adminLogin()
{
    Admin admin;

    cout<<"\n===== ADMIN LOGIN =====\n";

    cout<<"Enter Username: ";
    cin>>admin.username;

 cout<<"Enter Password: ";
admin.password = getPassword();

    if(admin.username=="admin" &&
   admin.password=="admin123")
    {
        setColor(10);
cout<<"\nAdmin Login Successful!\n";
setColor(7);
    }
    else
    {
      setColor(12);
cout<<"\nInvalid Admin Credentials!\n";
setColor(7);
    }
}


void searchJob()
{
    string keyword;
    string line;
    bool found=false;

    cin.ignore();

    cout<<"\nEnter Job Title or Company Name: ";
    getline(cin,keyword);

    ifstream file("jobs.txt");

    cout<<"\n===== SEARCH RESULTS =====\n";

    while(getline(file,line))
    {
        if(line.find(keyword)!=string::npos)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    file.close();

    if(!found)
    {
        cout<<"\nNo Job Found!\n";
    }
}


void deleteJob()
{
    string keyword;
    string line;

    cin.ignore();

    cout<<"\nEnter Company Name to Delete: ";
    getline(cin, keyword);

    ifstream infile("jobs.txt");
    ofstream outfile("temp.txt");

    bool found = false;

    while(getline(infile,line))
    {
        if(line.find(keyword)==string::npos)
        {
            outfile<<line<<endl;
        }
        else
        {
            found = true;
        }
    }

    infile.close();
    outfile.close();

    remove("jobs.txt");
    rename("temp.txt","jobs.txt");

    if(found)
        cout<<"\nJob Deleted Successfully!\n";
    else
        cout<<"\nJob Not Found!\n";
}




void updateApplicationStatus()
{
    string applicant, line, status;

    cin.ignore();

    cout << "\nEnter Applicant Name: ";
    getline(cin, applicant);

    cout << "\nSelect Application Status:\n";
    cout << "1. Pending\n";
    cout << "2. Applied\n";
    cout << "3. Accepted\n";
    cout << "4. Rejected\n";
    cout << "5. Selected\n";
    cout << "6. Without Status\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
        status = "Pending";
    else if (choice == 2)
        status = "Applied";
    else if (choice == 3)
        status = "Accepted";
    else if (choice == 4)
        status = "Rejected";
    else if (choice == 5)
        status = "Selected";
    else if (choice == 6)
        status = "";
    else
    {
        cout << "\nInvalid choice!\n";
        return;
    }

    ifstream infile("applications.txt");

    if (!infile)
    {
        cout << "\nUnable to open applications.txt!\n";
        return;
    }

    ofstream outfile("temp.txt");

    if (!outfile)
    {
        infile.close();
        cout << "\nUnable to create temporary file!\n";
        return;
    }

    bool found = false;

    while (getline(infile, line))
    {
        size_t p1 = line.find('|');

        if (p1 != string::npos &&
            line.substr(0, p1) == applicant)
        {
            size_t p2 = line.find('|', p1 + 1);
            size_t p3 = string::npos;

            if (p2 != string::npos)
                p3 = line.find('|', p2 + 1);

            if (p2 == string::npos)
            {
                // Existing format: Applicant|Status
                outfile << applicant << "|" << status << endl;
            }
            else if (p3 == string::npos)
            {
                // Existing format: Applicant|Company|Job
                outfile << line << "|" << status << endl;
            }
            else
            {
                // Preserve applicant, company, and job;
                // replace the existing status field.
                outfile << line.substr(0, p3 + 1)
                        << status << endl;
            }

            found = true;
           ofstream notificationFile("notifications.txt", ios::app);

if (notificationFile)
{
    notificationFile << applicant << "|"
                     << "Your application status has been updated to: "
                     << status << endl;

    notificationFile.close();
}
        }
        else
        {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    if (!found)
    {
        remove("temp.txt");
        cout << "\nApplicant Not Found!\n";
        return;
    }

    if (remove("applications.txt") != 0)
    {
        remove("temp.txt");
        cout << "\nUnable to replace applications.txt!\n";
        return;
    }

    if (rename("temp.txt", "applications.txt") != 0)
    {
        cout << "\nUnable to rename temporary file!\n";
        return;
    }

    cout << "\nApplication Status Updated Successfully!\n";

    if (status.empty())
        cout << "New Status: Without Status\n";
    else
        cout << "New Status: " << status << endl;
}



void viewUsers()
{
    string line;

    ifstream file("users.txt");

    cout<<"\n===== REGISTERED USERS =====\n\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}


void deleteUser()
{
    string email;
    string line;

    cin.ignore();

    cout<<"\nEnter User Email to Delete: ";
    getline(cin,email);

    ifstream infile("users.txt");
    ofstream outfile("temp.txt");

    bool found=false;

    while(getline(infile,line))
    {
        if(line.find(email)==string::npos)
        {
            outfile<<line<<endl;
        }
        else
        {
            found=true;
        }
    }

    infile.close();
    outfile.close();

    remove("users.txt");
    rename("temp.txt","users.txt");

    if(found)
        cout<<"\nUser Deleted Successfully!\n";
    else
        cout<<"\nUser Not Found!\n";
}


void dashboard()
{
	setColor(11);
cout<<"\n==============================";
cout<<"\n      ADMIN DASHBOARD";
cout<<"\n==============================";
setColor(7);

    string line;
    int users = 0;
    int jobs = 0;
    int applications = 0;

    ifstream userFile("users.txt");
    while(getline(userFile,line))
        users++;
    userFile.close();

    ifstream jobFile("jobs.txt");
    while(getline(jobFile,line))
        jobs++;
    jobFile.close();

    ifstream appFile("applications.txt");
    while(getline(appFile,line))
        applications++;
    appFile.close();

   
    cout<<"\nTotal Users        : "<<users;
    cout<<"\nTotal Jobs         : "<<jobs;
    cout<<"\nTotal Applications : "<<applications;
    cout<<"\n==============================\n";
}


void searchApplicant()
{
    string keyword;
    string line;
    bool found = false;

    cin.ignore();

    cout<<"\nEnter Applicant Name: ";
    getline(cin, keyword);

    ifstream file("applications.txt");

    cout<<"\n===== SEARCH RESULT =====\n";

    while(getline(file,line))
    {
        if(line.find(keyword) != string::npos)
        {
            cout<<line<<endl;
            found = true;
        }
    }

    file.close();

    if(!found)
    {
        cout<<"\nApplicant Not Found!\n";
    }
}


void viewJobByID()
{
    string id;
    string line;
    bool found = false;

    cin.ignore();

    cout<<"\nEnter Job ID: ";
    getline(cin,id);

    ifstream file("jobs.txt");

    cout<<"\n===== JOB DETAILS =====\n";

    while(getline(file,line))
    {
        if(line.find(id + "|") == 0)
        {
            cout<<line<<endl;
            found = true;
            break;
        }
    }

    file.close();

    if(!found)
    {
        cout<<"\nJob Not Found!\n";
    }
}


void setColor(int color)
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        color
    );
}

string getPassword()
{
    string password="";
    char ch;

    while((ch=getch())!=13)
    {
        if(ch==8)
        {
            if(password.length()>0)
            {
                password.erase(password.length()-1,1);
                cout<<"\b \b";
            }
        }
        else
        {
            password += ch;
            cout<<"*";
        }
    }

    cout<<endl;
    return password;
}


void changePassword()
{
    string email;
    string oldPass;
    string newPass;
    string line;

    cin.ignore();

    cout<<"\nEnter Email: ";
    getline(cin,email);

    cout<<"Enter Old Password: ";
    getline(cin,oldPass);

    cout<<"Enter New Password: ";
    getline(cin,newPass);

    ifstream infile("users.txt");
    ofstream outfile("temp.txt");

    bool found=false;

    while(getline(infile,line))
    {
        if(line.find(email)!=string::npos &&
           line.find(oldPass)!=string::npos)
        {
            size_t pos=line.find(oldPass);

            if(pos!=string::npos)
            {
                line.replace(pos,oldPass.length(),newPass);
                found=true;
            }
        }

        outfile<<line<<endl;
    }

    infile.close();
    outfile.close();

    remove("users.txt");
    rename("temp.txt","users.txt");

    if(found)
        cout<<"\nPassword Changed Successfully!\n";
    else
        cout<<"\nInvalid Email or Password!\n";
}


void editProfile()
{
    string email;
    string newPhone;
    string line;

    cin.ignore();

    cout<<"\nEnter Email: ";
    getline(cin,email);

    cout<<"Enter New Phone Number: ";
    getline(cin,newPhone);

    ifstream infile("users.txt");
    ofstream outfile("temp.txt");

    bool found = false;

    while(getline(infile,line))
    {
        if(line.find(email) != string::npos)
        {
            found = true;

            size_t pos1 = line.find("|");
            size_t pos2 = line.find("|", pos1+1);
            size_t pos3 = line.find("|", pos2+1);
            size_t pos4 = line.find("|", pos3+1);

            line.replace(pos3+1, pos4-pos3-1, newPhone);
        }

        outfile<<line<<endl;
    }

    infile.close();
    outfile.close();

    remove("users.txt");
    rename("temp.txt","users.txt");

    if(found)
        cout<<"\nProfile Updated Successfully!\n";
    else
        cout<<"\nUser Not Found!\n";
}


void searchByCategory()
{
    string category;
    string line;
    bool found=false;

    cin.ignore();

    cout<<"\nEnter Category (IT/HR/Finance): ";
    getline(cin,category);

    ifstream file("jobs.txt");

    cout<<"\n===== CATEGORY JOBS =====\n";

    while(getline(file,line))
    {
        if(line.find(category)!=string::npos)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    file.close();

    if(!found)
    {
        cout<<"\nNo Jobs Found!\n";
    }
}


void addCompany()
{
    Company company;

    cin.ignore();

    cout<<"\n===== ADD COMPANY =====\n";

    cout<<"Enter Company Name: ";
    getline(cin, company.companyName);

    cout<<"Enter Location: ";
    getline(cin, company.location);

    ofstream file("companies.txt", ios::app);

    file << company.companyName << "|"
         << company.location << endl;

    file.close();

    cout<<"\nCompany Added Successfully!\n";
}


void viewCompanies()
{
    string line;

    ifstream file("companies.txt");

    cout<<"\n===== COMPANY LIST =====\n\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}


void deleteCompany()
{
    string companyName;
    string line;

    cin.ignore();

    cout<<"\nEnter Company Name to Delete: ";
    getline(cin, companyName);

    ifstream infile("companies.txt");
    ofstream outfile("temp.txt");

    bool found = false;

    while(getline(infile,line))
    {
        if(line.find(companyName)==string::npos)
        {
            outfile<<line<<endl;
        }
        else
        {
            found = true;
        }
    }

    infile.close();
    outfile.close();

    remove("companies.txt");
    rename("temp.txt","companies.txt");

    if(found)
        cout<<"\nCompany Deleted Successfully!\n";
    else
        cout<<"\nCompany Not Found!\n";
}


void uploadResume()
{
    string name;
    string resumePath;

    cin.ignore();

    cout<<"\n===== RESUME UPLOAD =====\n";

    cout<<"Enter Applicant Name: ";
    getline(cin,name);

    cout<<"Enter Resume File Path: ";
    getline(cin,resumePath);

    ofstream file("resumes.txt", ios::app);

    file << name << "|"
         << resumePath << endl;

    file.close();

    cout<<"\nResume Uploaded Successfully!\n";
}


void viewResumes()
{
    string line;

    ifstream file("resumes.txt");

    cout<<"\n===== RESUME LIST =====\n\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}


void openResume()
{
    string applicantName;
    string line;

    cin.ignore();

    cout<<"\n===== OPEN RESUME =====\n";

    cout<<"Enter Applicant Name: ";
    getline(cin, applicantName);

    ifstream file("resumes.txt");

    bool found = false;

    while(getline(file,line))
    {
        size_t pos = line.find("|");

        if(pos != string::npos)
        {
            string name = line.substr(0,pos);
            string path = line.substr(pos+1);

            if(name == applicantName)
            {
                found = true;

                string command =
                "start \"\" \"" + path + "\"";

                system(command.c_str());

                cout<<"\nOpening Resume...\n";

                break;
            }
        }
    }

    file.close();

    if(!found)
    {
        cout<<"\nResume Not Found!\n";
    }
}


void openResumeFromApplication()
{
    string applicantName;
    string line;

    cin.ignore();

    cout<<"\n===== OPEN RESUME =====\n";

    cout<<"Enter Applicant Name: ";
    getline(cin, applicantName);

    ifstream resumeFile("resumes.txt");

    bool found = false;

    while(getline(resumeFile,line))
    {
        size_t pos = line.find("|");

        if(pos != string::npos)
        {
            string name = line.substr(0,pos);
            string path = line.substr(pos+1);

            if(name == applicantName)
            {
                found = true;

                string command =
                "start \"\" \"" + path + "\"";

                system(command.c_str());

                cout<<"\nOpening Resume...\n";

                break;
            }
        }
    }

    resumeFile.close();

    if(!found)
    {
        cout<<"\nResume Not Found!\n";
    }
}


void saveJob()
{
    string userName;
    string jobID;

    cin.ignore();

    cout<<"\n===== SAVE JOB =====\n";

    cout<<"Enter User Name: ";
    getline(cin,userName);

    cout<<"Enter Job ID: ";
    getline(cin,jobID);

    ofstream file("savedjobs.txt",ios::app);

    file<<userName<<"|"
        <<jobID<<endl;

    file.close();

    cout<<"\nJob Saved Successfully!\n";
}


void viewSavedJobs()
{
    string userName;
    string line;

    cin.ignore();

    cout<<"\nEnter User Name: ";
    getline(cin,userName);

    ifstream file("savedjobs.txt");

    bool found=false;

    cout<<"\n===== SAVED JOBS =====\n";

    while(getline(file,line))
    {
        if(line.find(userName+"|")==0)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    file.close();

    if(!found)
    {
        cout<<"\nNo Saved Jobs Found!\n";
    }
}

void recommendJobs()
{
    string userEmail;
    string userSkill = "";
    string line;

    cin.ignore();

    cout<<"\n===== JOB RECOMMENDATION =====\n";

    cout<<"Enter User Email: ";
    getline(cin,userEmail);

    ifstream userFile("users.txt");

    while(getline(userFile,line))
    {
        if(line.find(userEmail)!=string::npos)
        {
            int count = 0;
            size_t start = 0;
            size_t end;

            while(count < 5)
            {
                end = line.find("|", start);

                if(end == string::npos)
                    break;

                start = end + 1;
                count++;
            }

            userSkill = line.substr(start);
            break;
        }
    }

    userFile.close();

    if(userSkill=="")
    {
        cout<<"\nUser Not Found!\n";
        return;
    }

    cout<<"\nUser Skill: "<<userSkill<<endl;

    ifstream jobFile("jobs.txt");

    bool found=false;

    cout<<"\n===== RECOMMENDED JOBS =====\n";

    while(getline(jobFile,line))
    {
        if(line.find(userSkill)!=string::npos)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    jobFile.close();

    if(!found)
    {
        cout<<"\nNo Matching Jobs Found!\n";
    }
}

void scheduleInterview()
{
    Interview interview;

    cin.ignore();

    cout << "\n===== SCHEDULE INTERVIEW =====\n";

    cout << "Enter Applicant Name: ";
    getline(cin, interview.applicantName);

    cout << "Enter Company Name: ";
    getline(cin, interview.companyName);

    cout << "Enter Job Title: ";
    getline(cin, interview.jobTitle);

    cout << "Enter Interview Date (DD-MM-YYYY): ";
    getline(cin, interview.date);

    cout << "Enter Interview Time (e.g. 11:00 AM): ";
    getline(cin, interview.time);

    ofstream file("interviews.txt", ios::app);

    if (!file)
    {
        cout << "\nUnable to open interview file!\n";
        return;
    }

    file << interview.applicantName << "|"
         << interview.companyName << "|"
         << interview.jobTitle << "|"
         << interview.date << "|"
         << interview.time << endl;

    file.close();

    cout << "\nInterview Scheduled Successfully!\n";
}

void viewInterviews()
{
    string line;

    ifstream file("interviews.txt");

    cout << "\n========================================\n";
    cout << "          INTERVIEW SCHEDULE\n";
    cout << "========================================\n";

    if (!file)
    {
        cout << "No interview records found.\n";
        return;
    }

    bool found = false;

    while (getline(file, line))
    {
        cout << line << endl;
        found = true;
    }

    if (!found)
        cout << "No interviews scheduled yet.\n";

    file.close();
}


void generateReport()
{
    string line;
    int users = 0, jobs = 0, applications = 0;
    int companies = 0, interviews = 0;

    ifstream userFile("users.txt");
    while (getline(userFile, line))
        if (line != "")
            users++;
    userFile.close();

    ifstream jobFile("jobs.txt");
    while (getline(jobFile, line))
        if (line != "")
            jobs++;
    jobFile.close();

    ifstream applicationFile("applications.txt");
    while (getline(applicationFile, line))
        if (line != "")
            applications++;
    applicationFile.close();

    ifstream companyFile("companies.txt");
    while (getline(companyFile, line))
        if (line != "")
            companies++;
    companyFile.close();

    ifstream interviewFile("interviews.txt");
    while (getline(interviewFile, line))
        if (line != "")
            interviews++;
    interviewFile.close();

    cout << "\n========================================\n";
    cout << "            ADMIN REPORT\n";
    cout << "========================================\n";
    cout << "Total Users: " << users << endl;
    cout << "Total Jobs: " << jobs << endl;
    cout << "Total Applications: " << applications << endl;
    cout << "Total Companies: " << companies << endl;
    cout << "Total Interviews: " << interviews << endl;
    cout << "========================================\n";

    ofstream reportFile("admin_report.txt");

    if (reportFile)
    {
        reportFile << "========== ADMIN REPORT ==========\n";
        reportFile << "Total Users: " << users << endl;
        reportFile << "Total Jobs: " << jobs << endl;
        reportFile << "Total Applications: " << applications << endl;
        reportFile << "Total Companies: " << companies << endl;
        reportFile << "Total Interviews: " << interviews << endl;
        reportFile.close();

        cout << "\nReport saved to admin_report.txt\n";
    }
    else
    {
        cout << "\nUnable to save report!\n";
    }
}


void updateInterview()
{
    string line, name;
    string company, job, date, time;
    ifstream file("interviews.txt");
    ofstream temp("temp.txt");

    if (!file || !temp)
    {
        cout << "\nUnable to open interview files!\n";
        return;
    }

    cout << "\nEnter applicant name to update: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;

    while (getline(file, line))
    {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        size_t p4 = line.find('|', p3 + 1);

        if (p1 != string::npos &&
            p2 != string::npos &&
            p3 != string::npos &&
            p4 != string::npos &&
            line.substr(0, p1) == name)
        {
            company = line.substr(p1 + 1, p2 - p1 - 1);
            job = line.substr(p2 + 1, p3 - p2 - 1);

            cout << "Enter new interview date (DD-MM-YYYY): ";
            getline(cin, date);

            cout << "Enter new interview time: ";
            getline(cin, time);

            temp << name << "|" << company << "|" << job
                 << "|" << date << "|" << time << endl;

            found = true;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("interviews.txt");
    rename("temp.txt", "interviews.txt");

    if (found)
        cout << "\nInterview updated successfully!\n";
    else
        cout << "\nApplicant interview not found!\n";
}


void deleteInterview()
{
    string line, name;
    ifstream file("interviews.txt");
    ofstream temp("temp.txt");

    if (!file || !temp)
    {
        cout << "\nUnable to open interview files!\n";
        return;
    }

    cout << "\nEnter applicant name to delete interview: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;

    while (getline(file, line))
    {
        size_t p = line.find('|');

        if (p != string::npos &&
            line.substr(0, p) == name)
        {
            found = true;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("interviews.txt");
    rename("temp.txt", "interviews.txt");

    if (found)
        cout << "\nInterview deleted successfully!\n";
    else
        cout << "\nApplicant interview not found!\n";
}


void searchInterview()
{
    string line, name;
    bool found = false;

    ifstream file("interviews.txt");

    if (!file)
    {
        cout << "\nUnable to open interview file!\n";
        return;
    }

    cin.ignore();
    cout << "\nEnter Applicant Name to Search: ";
    getline(cin, name);

    cout << "\n========== SEARCH RESULT ==========\n";

    while (getline(file, line))
    {
        size_t p = line.find('|');

        if (p != string::npos && line.substr(0, p) == name)
        {
            cout << "Interview Details: " << line << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo interview found for " << name << ".\n";
    }

    file.close();
}


void exportJobsToCSV()
{
    ifstream file("jobs.txt");
    ofstream csvFile("jobs_report.csv");

    if (!file || !csvFile)
    {
        cout << "\nUnable to open files!\n";
        return;
    }

    csvFile << "Job ID,Company,Job Title,Category,Location,Salary\n";

    string line;
    int count = 0;

    while (getline(file, line))
    {
        string fields[6];
        int field = 0;
        size_t start = 0;
        size_t pos;

        while ((pos = line.find('|', start)) != string::npos
               && field < 5)
        {
            fields[field++] = line.substr(start, pos - start);
            start = pos + 1;
        }

        if (field < 6)
            fields[field++] = line.substr(start);

        // Export only records containing all six fields.
        if (field == 6)
        {
            for (int i = 0; i < 6; i++)
            {
                if (i > 0)
                    csvFile << ",";

                // Quote fields so commas in values are handled.
                csvFile << "\"";

                for (int j = 0; j < fields[i].length(); j++)
                {
                    if (fields[i][j] == '"')
                        csvFile << "\"\"";
                    else
                        csvFile << fields[i][j];
                }

                csvFile << "\"";
            }

            csvFile << "\n";
            count++;
        }
    }

    file.close();
    csvFile.close();

    cout << "\nJobs exported successfully!\n";
    cout << "Total jobs exported: " << count << endl;
    cout << "File name: jobs_report.csv\n";
}


void exportInterviewsToCSV()
{
    ifstream file("interviews.txt");
    ofstream csvFile("interviews_report.csv");

    if (!file || !csvFile)
    {
        cout << "\nUnable to open files!\n";
        return;
    }

    csvFile << "Applicant Name,Company Name,Job Title,Date,Time\n";

    string line;
    int count = 0;

    while (getline(file, line))
    {
        string fields[5];
        size_t start = 0;
        size_t pos;
        int field = 0;

        while ((pos = line.find('|', start)) != string::npos
               && field < 4)
        {
            fields[field++] = line.substr(start, pos - start);
            start = pos + 1;
        }

        fields[field++] = line.substr(start);

        if (field == 5)
        {
            for (int i = 0; i < 5; i++)
            {
                if (i > 0)
                    csvFile << ",";

                csvFile << "\"";

                for (int j = 0; j < fields[i].length(); j++)
                {
                    if (fields[i][j] == '"')
                        csvFile << "\"\"";
                    else
                        csvFile << fields[i][j];
                }

                csvFile << "\"";
            }

            csvFile << "\n";
            count++;
        }
    }

    file.close();
    csvFile.close();

    cout << "\nInterview schedules exported successfully!\n";
    cout << "Total records exported: " << count << endl;
    cout << "File name: interviews_report.csv\n";
}



void applicationStatusReport()
{
    ifstream file("applications.txt");

    if (!file)
    {
        cout << "\nUnable to open applications.txt!\n";
        return;
    }

    string line;
    int total = 0;
    int pending = 0;
    int applied = 0;
    int accepted = 0;
    int rejected = 0;
    int selected = 0;
    int unknown = 0;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        total++;

        size_t pos = line.find_last_of('|');
        string status = "";

        if (pos != string::npos)
            status = line.substr(pos + 1);

        if (status == "Pending")
            pending++;
        else if (status == "Applied")
            applied++;
        else if (status == "Accepted")
            accepted++;
        else if (status == "Rejected")
            rejected++;
        else if (status == "Selected")
            selected++;
        else
            unknown++;
    }

    file.close();

    cout << "\n========== APPLICATION STATUS REPORT ==========\n";
    cout << "Total Applications : " << total << endl;
    cout << "Pending            : " << pending << endl;
    cout << "Applied            : " << applied << endl;
    cout << "Accepted           : " << accepted << endl;
    cout << "Rejected           : " << rejected << endl;
    cout << "Selected           : " << selected << endl;
    cout << "Without Status     : " << unknown << endl;
    cout << "===============================================\n";
}


void viewApplicationsByStatus()
{
    ifstream file("applications.txt");

    if (!file)
    {
        cout << "\nUnable to open applications.txt!\n";
        return;
    }

    string status, line;

    cout << "\n===== VIEW APPLICATIONS BY STATUS =====\n";
    cout << "1. Pending\n";
    cout << "2. Applied\n";
    cout << "3. Accepted\n";
    cout << "4. Rejected\n";
    cout << "5. Selected\n";
    cout << "6. Without Status\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
        status = "Pending";
    else if (choice == 2)
        status = "Applied";
    else if (choice == 3)
        status = "Accepted";
    else if (choice == 4)
        status = "Rejected";
    else if (choice == 5)
        status = "Selected";
    else if (choice == 6)
        status = "";
    else
    {
        cout << "\nInvalid choice!\n";
        file.close();
        return;
    }

    bool found = false;

    cout << "\n===== FILTERED APPLICATIONS =====\n";

    while (getline(file, line))
    {
        size_t pos = line.find_last_of('|');
        string currentStatus = "";

        if (pos != string::npos)
            currentStatus = line.substr(pos + 1);

        if (currentStatus == status)
        {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No applications found for this status.\n";

    file.close();
}



void searchApplicationsByCompany()
{
    ifstream file("applications.txt");

    if (!file)
    {
        cout << "\nUnable to open applications.txt!\n";
        return;
    }

    string company, line;
    bool found = false;

    cin.ignore();

    cout << "\nEnter Company Name: ";
    getline(cin, company);

    cout << "\n===== APPLICATIONS FOR " << company << " =====\n";

    while (getline(file, line))
    {
        size_t p1 = line.find('|');

        if (p1 == string::npos)
            continue;

        size_t p2 = line.find('|', p1 + 1);

        if (p2 == string::npos)
            continue;

        string companyName = line.substr(p1 + 1, p2 - p1 - 1);

        if (companyName == company)
        {
            cout << line << endl;
            found = true;
        }
    }

    file.close();

    if (!found)
        cout << "No applications found for this company.\n";
}


void viewMyApplications()
{
    ifstream file("applications.txt");

    if (!file)
    {
        cout << "\nUnable to open applications.txt!\n";
        return;
    }

    string applicant, line;
    bool found = false;

    cin.ignore();

    cout << "\nEnter Your Name: ";
    getline(cin, applicant);

    cout << "\n========== MY APPLICATIONS ==========\n";

    while (getline(file, line))
    {
        size_t p1 = line.find('|');

        if (p1 == string::npos)
            continue;

        string name = line.substr(0, p1);

        if (name == applicant)
        {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No applications found for this applicant.\n";

    file.close();
}


void withdrawApplication()
{
    string applicant, company, job, line;
    bool found = false;

    cin.ignore();

    cout << "\n===== WITHDRAW APPLICATION =====\n";
    cout << "Enter Your Name: ";
    getline(cin, applicant);

    cout << "Enter Company Name: ";
    getline(cin, company);

    cout << "Enter Job Title: ";
    getline(cin, job);

    ifstream infile("applications.txt");

    if (!infile)
    {
        cout << "\nUnable to open applications.txt!\n";
        return;
    }

    ofstream outfile("temp.txt");

    if (!outfile)
    {
        infile.close();
        cout << "\nUnable to create temporary file!\n";
        return;
    }

    while (getline(infile, line))
    {
        size_t p1 = line.find('|');
        size_t p2 = string::npos;
        size_t p3 = string::npos;

        if (p1 != string::npos)
            p2 = line.find('|', p1 + 1);

        if (p2 != string::npos)
            p3 = line.find('|', p2 + 1);

        if (p1 != string::npos &&
            p2 != string::npos &&
            p3 != string::npos)
        {
            string savedName = line.substr(0, p1);
            string savedCompany =
                line.substr(p1 + 1, p2 - p1 - 1);
            string savedJob =
                line.substr(p2 + 1, p3 - p2 - 1);

            if (savedName == applicant &&
                savedCompany == company &&
                savedJob == job)
            {
                found = true;
                continue;  // Skip this application
            }
        }

        outfile << line << endl;
    }

    infile.close();
    outfile.close();

    if (!found)
    {
        remove("temp.txt");
        cout << "\nApplication not found!\n";
        return;
    }

    if (remove("applications.txt") != 0)
    {
        remove("temp.txt");
        cout << "\nUnable to update applications file!\n";
        return;
    }

    if (rename("temp.txt", "applications.txt") != 0)
    {
        cout << "\nUnable to rename temporary file!\n";
        return;
    }

    cout << "\nApplication withdrawn successfully!\n";
}


void viewApplicationReceipt()
{
    ifstream file("C:\\Users\\hp\\Desktop\\Online Job Portal - C++\\application_receipt.txt");

    if (!file)
    {
        cout << "\nNo application receipt found!\n";
        return;
    }

    string line;
    bool found = false;

    cout << "\n========== ALL APPLICATION RECEIPTS ==========\n";

    while (getline(file, line))
    {
        cout << line << endl;
        found = true;
    }

    if (!found)
        cout << "No receipts available.\n";

    file.close();
}

void deleteApplicationReceipt()
{
    string jobID, companyName;
    string line, receipt = "";
    string allReceipts = "";
    bool found = false;

    cout << "\n===== DELETE APPLICATION RECEIPT =====\n";

    cout << "Enter Job ID: ";
    cin >> jobID;

    cout << "Enter Company Name: ";
    cin.ignore();
    getline(cin, companyName);

    ifstream fin("C:\\Users\\hp\\Desktop\\Online Job Portal - C++\\application_receipt.txt");

    if (!fin)
    {
        cout << "\nReceipt file not found!\n";
        return;
    }

    while (getline(fin, line))
    {
        receipt += line + "\n";

        if (line.find("================================") != string::npos)
        {
            if (receipt.find(jobID) != string::npos &&
                receipt.find(companyName) != string::npos)
            {
                found = true;
                receipt = "";
            }
            else
            {
                allReceipts += receipt;
                receipt = "";
            }
        }
    }

    if (receipt != "")
        allReceipts += receipt;

    fin.close();

    if (!found)
    {
        cout << "\nMatching receipt not found!\n";
        return;
    }

    ofstream fout("C:\\Users\\hp\\Desktop\\Online Job Portal - C++\\application_receipt.txt");

    if (!fout)
    {
        cout << "\nUnable to update receipt file!\n";
        return;
    }

    fout << allReceipts;
    fout.close();

    cout << "\nApplication receipt deleted successfully!\n";
}

void viewApplicationNotifications()
{
    string applicantName;
    string applicant, notification;
    bool found = false;

    cin.ignore();

    cout << "\nEnter your applicant name: ";
    getline(cin, applicantName);

    ifstream file("notifications.txt");

    if (!file)
    {
        cout << "\nNo notifications found.\n";
        return;
    }

    while (getline(file, applicant, '|') &&
           getline(file, notification))
    {
        if (applicant == applicantName)
        {
            cout << "\nNotification: " << notification << endl;
            found = true;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nNo notifications available.\n";
    }
}


int main()
{
	
    int choice;

    do
    {
       setColor(14);

       cout<<"\n====================================";
       cout<<"\n      ONLINE JOB PORTAL";
       cout<<"\n====================================";

setColor(7);

        cout<<"\n1.  User Registration";
        cout<<"\n2.  User Login";
        cout<<"\n3.  Admin Login";
        cout<<"\n4.  Post Job";
        cout<<"\n5.  View Jobs";
        cout<<"\n6.  Search Job";
        cout<<"\n7.  Apply Job";
        cout<<"\n8.  View Applications";
        cout<<"\n9.  Delete Job";
        cout<<"\n10. Update Application Status";
        cout<<"\n11. View Registered Users";
        cout<<"\n12. Delete User";
        cout<<"\n13. Dashboard";
        cout<<"\n14. Search Applicant";
        cout<<"\n15. View Job By ID";
        cout<<"\n16. Change Password";
        cout<<"\n17. Edit Profile";
        cout<<"\n18. Search By Category";
        cout<<"\n19. Add Company";
        cout<<"\n20. View Companies";
        cout<<"\n21. Delete Company";
        cout<<"\n22. Upload Resume";
        cout<<"\n23. View Resumes";
        cout<<"\n24. Open Resume";
        cout<<"\n25. Open Resume From Applications";
        cout<<"\n26. Save Job";
        cout<<"\n27. View Saved Jobs";
        cout << "\n28. Job Recommendation";
        cout << "\n29. Schedule Interview";
        cout << "\n30. View Interviews";
        cout << "\n31. Generate Admin Report";
        cout << "\n32. Update Interview";
        cout << "\n33. Delete Interview";
        cout << "\n34. Search Interview";
        cout << "\n35. Export Jobs to CSV";
        cout << "\n36. Export Interviews to CSV";
        cout << "\n37. Application Status Report";
        cout << "\n38. View Applications by Status";
        cout << "\n39. Search Applications by Company";
        cout << "\n40. View My Applications";
        cout << "\n41. Withdraw Application";
        cout << "\n42. View Application Receipt";
        cout << "\n43. Delete Application Receipt";
        cout << "\n44. Application Status Notifications";
        cout << "\n45. Exit";
        
        cout<<"\n\nEnter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
               adminLogin();
                break;

            case 4:
                 postJob();
                break;

            case 5:
                viewJobs();
                break;

            case 6:
                searchJob();
                break;
            case 7:
                applyJob();
                break;

            case 8:
                viewApplications();
                break;

            case 9:
                deleteJob();
                break;

            case 10:
                updateApplicationStatus();
                break;

            case 11:
                viewUsers();
                break;

            case 12:
                deleteUser();
                break;

            case 13:
                dashboard();
                break;

            case 14:
                searchApplicant();
                break;

            case 15:
                viewJobByID();
                break;
    
           case 16:
                changePassword();
                break;

           case 17:
                editProfile();
                break;

           case 18:
                searchByCategory();
                break;

           case 19:
                addCompany();
                break;

           case 20:
                viewCompanies();
                break;

           case 21:
                deleteCompany();
                break;

           case 22:
               uploadResume();
               break;

           case 23:
               viewResumes();
               break;

           case 24:
               openResume();
                break;

           case 25:
               openResumeFromApplication();
               break;

           case 26:
               saveJob();
               break;

           case 27:
               viewSavedJobs();
               break;

            case 28:
               recommendJobs();
               break;

          case 29:
               scheduleInterview();
               break;

          case 30:
               viewInterviews();
               break;

          case 31:
               generateReport();
               break;

          case 32:
               updateInterview();
               break;

          case 33:
               deleteInterview();
               break;

          case 34:
                searchInterview();
                break;

            case 35:
                exportJobsToCSV();
                break;

            case 36:
                exportInterviewsToCSV();
                break;

            case 37:
                applicationStatusReport();
                break;

           case 38:
                viewApplicationsByStatus();
                break;

           case 39:
                searchApplicationsByCompany();
                break;

           case 40:
                viewMyApplications();
                break;

           case 41:
                withdrawApplication();
                break;

            case 42:
                viewApplicationReceipt();
                break;
            
            case 43:
                deleteApplicationReceipt();
                break;
                
            case 44:
                viewApplicationNotifications();
                break;
                
            case 45:
                cout << "\nThank You!\n";
                break;
               
               
            default:
                cout<<"\nInvalid Choice!";
        }

    } while(choice != 45);

    return 0;
}
