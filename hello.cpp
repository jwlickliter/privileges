// *************************************************************************************************
// Legal Stuff
//
// Privleges#    Ver. .01    PreAlpha
//
// Developed by: Jason Lickiter  
//
// Hacking game based in the '80s
//
// Copyright © 2015 Jason Lickliter
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software Foundation,
// either version 3 of the license, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.
// If not, see <http://www.gnu.org/licenses/>
// 
// My contact by email is jwlickliter@gmail.com
//
// **********************************************************************************************
//
// I made this using aide for android.
//
// You will need to change the file path for the files in the code 
// before you compile.
// 
// There is a gameFiles folder. Make sure your locations point to this 
// folder or move the game files all ready located there to your new 
// location.


#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <cstddef>
#include <iomanip>


using namespace std; 

// Functions

const std::string currentDateTime() 
{
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X %d/%m/81", &tstruct);

    return buf;
}

int driveMenu()
{
	cout << string( 100, '\n' );
	cout << "  ***********************************************************" << endl;  
	cout << "  *                                                         *" << endl;        
	cout << "  *    Drive Manager V.2.6 Devloped by: Jason Lickliter     *" << endl;         
	cout << "  *                                                         *" << endl;           
	cout << "  *---------------------------------------------------------*------------------------" << endl;
	cout << "  |                                                         |                       |" << endl;
	cout << "  |   Menu Options                                          |   Drive Information   |" << endl;
	cout << "  |   ------------                                          |   -----------------   |" << endl;
	cout << "  |                                                         |                       |" << endl;
	cout << "  |   [1]--Create Directory        [2]--Copy File           |   [7]--Hard Drive(s)  |" << endl;
	cout << "  |                                                         |                       |" << endl;
	cout << "  |   [3]--Move File               [4]--Delete File/Dir     |   [8]--Cpu            |" << endl;
	cout << "  |                                                         |                       |" << endl;
	cout << "  |   [5]--Rename File             [6]--Format Hard Drive   |   [9]--Memory         |" << endl;
	cout << "  |                                                         |                       |" << endl;
	cout << "  |                   Type /exit/ To Quit                   |   [10]--Log File      |" << endl;
	cout << "  |                                                         |                       |" << endl;
	cout << "  |          <<  Drive Manager Copyright 1981  >>           |                       |" << endl;
	cout << "  |                                                         |                       |" << endl;
	cout << "  *---------------------------------------------------------*------------------------" << endl;
	cout << endl;
}

int msleep(unsigned long milisec)   
{   
    struct timespec req={0};   
    time_t sec=(int)(milisec/1000);   
    milisec=milisec-(sec*1000);   
    req.tv_sec=sec;   
    req.tv_nsec=milisec*1000000L;   
    while(nanosleep(&req,&req)==-1)   
        continue;   
    return 1;   
}   

int main()
{
	//For cppdroid
	msleep(2000);
	
	//Seed random number
	srand(static_cast<unsigned int>(time(0)));
	
	char line3[256];
	char exit[256] = "<EOF>";
	
	string userInput;
	string promptName = "[C$//]";
	string line;
	string line1;
	string output;
	string output1;
	string output2;
	string dirLoc;
	string dirLoc1;
	string timeDate = currentDateTime();
	
	string myAddy = "jwlickliter@freedom.com";
	
	const int MAX_COM = 1024;
	const int MAX_DIR = 256;
	const int MAX_FILE = 256;
	const int MAX_NET = 1024;
	const int MAX_COPY = 256;
	const int maxChar = 10;
	
	int errorCode = 0;
	int dirChange = 0;
	int thisData = 0;
	int increase = 0;
	int lineOut = 1;
	int newLineChecker = 0;
	
	int fileSize = 0;
	float result = 0;
	int downloadTime = 0;
	int downloadTime1 = 0;
	int speedReduce = 0;
	int bpsModem = 4800; //Set modem bps
	
	int hour = 0;
	int minute = 0;
	int second = 0;
	
	string osCom[MAX_COM];
	string dirNames[MAX_DIR];
	string fileNames[MAX_FILE];
	string netCom[MAX_NET];
	
	string userDir[MAX_DIR];
	string user1Files[MAX_FILE];
	
	string copyArray[MAX_COPY];
	string copyArray1[MAX_COPY];
	
	//Add OS commands to array
	ifstream com_file ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/oscom.txt");
	if (com_file.is_open())
	{
		for(int i=0; !com_file.eof(); i++)
		{
			getline (com_file,line1);
			osCom[i] = line1;
		}
	}
	com_file.close();
	
	//Add net commands to array
	
	netCom[0] = "1";
	netCom[1] = "2";
	netCom[2] = "3";
	netCom[3] = "4";
	netCom[4] = "5";
	
	//Add starting hard drive structure
	
	dirNames[0] = "boot --- DIR ------- 5b -------- 10:17 2/18/81";
	dirNames[1] = "user --- DIR ------- 101mb ----- 21:12 2/18/81";
	dirNames[2] = "Images --- DIR ------- 0b -------- 21:16 2/18/81";
	dirNames[3] = "NetFiles --- DIR ------- 0b -------- 21:16 2/18/81";
	dirNames[4] = "Documents --- DIR ------- 0b -------- 21:18 2/18/81";
	dirNames[5] = "Programs --- DIR ------- 0b -------- 21:16 2/18/81";
	
	//Add starting files
	
	fileNames[0] = "JsonGuide.txt --- FILE ------ 1418b ----- 8:03 2/18/81";
	fileNames[1] = "boot.ini --- FILE ------ 736b ------ 8:03 2/18/81";
	fileNames[2] = "drivers.sys --- FILE ------ 8016kb ---- 8:04 2/18/81";
	fileNames[3] = "sound.sys --- FILE ------ 1227kb ---- 8:04 2/18/81";
	fileNames[4] = "cpu.sys --- FILE ------ 734b ------ 8:04 2/18/81";
	fileNames[5] = "logFile.bin --- ENCRYPT --- 0b -------- 8:05 2/18/81";
	
	
	//Add user directory's and files
	ifstream in_file ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDir.txt");
	if (in_file.is_open())
	{
		for(int i=0; !in_file.eof(); i++)
		{
			getline (in_file,line);
			userDir[i] = line;
		}
	}
	in_file.close();
	
	//Opening welcome screen for JsonOS
	ifstream welfile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/JsonWelcomeText.txt");
	if (welfile.is_open())
	{
		for(int i=0; !welfile.eof(); i++)
		{
			getline (welfile,line1);
			msleep(100);
			cout << line1 << endl;
			
		}
	}
	welfile.close();
	
	cout << endl;
	cout << "Type 'help' for a list of commands!" << endl;
	cout << endl;
	cout << "User guide file is in the root" << endl;
	cout << "directory. User guide file name" << endl;
	cout << "is JsonGuide.txt." << endl;
	cout << endl;
	cout << "Use 'read.JsonGuide.txt' to view" << endl;
	cout << "the file." << endl;
	cout << endl;
	
	do
	{
		cout << promptName;
		cin >> userInput;
		
		for (int i = 0; i < MAX_COM; ++i)
		{
			if (userInput == osCom[i])
			{
				if (userInput == "read.logFile.bin")
				{
					ifstream encryptFile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/MyFile.txt");
					if (encryptFile.is_open())
					{
						for(int i=0; !encryptFile.eof(); i++)
						{
							getline (encryptFile,line);
							msleep(75);
							cout << line << endl;
									
						}
						
					}
					encryptFile.close();
				}
				if (userInput == "help")
				{
					cout << endl;
					cout << "  <------------------------------------------------------------->" << endl;
					cout << "    |                                                         |" << endl;
					cout << "    |  [Basic Commands]                                       |" << endl;
					cout << "    |                                                         |" << endl;
					cout << "    |     list          cd            cd..          net.isp   |" << endl;
					cout << "    |                                                         |" << endl;
					cout << "    |     net.phone     new           help          cls       |" << endl;
					cout << "    |                                                         |" << endl;
					cout << "    |     read          netInfo       driveMgr      exit      |" << endl;
					cout << "    |                                                         |" << endl;
					cout << "  <------------------------------------------------------------->" << endl;
					cout << endl;
					cout << "More complete list with details read the user guide" << endl;
					cout << endl;
				}
				if (userInput == "cls")
				{
					cout << string( 100, '\n' );
				}
				if (userInput == "driveMgr")
				{
					cout << endl;
					cout << "Loading..." << endl;
					int choice7 = (rand() % 3000+1000);
					msleep(choice7);
					
					driveMenu();
					
					promptName = "[C#//driveMgr/]";
					
					do
					{
						cout << promptName;
						cin >> userInput;
					
						if (userInput == "1")
						{
							//Create directory
							cout << endl;
							do
							{
								cout << "Enter directory name >> ";
								cin >> userInput;
								//getline(cin, userInput);
								if (userInput.size() > maxChar)
								{
									cout << "<< Name must be 10 charaters or less >>" << endl;
								}
							} while (userInput.size() > maxChar);
							copyArray[0] = userInput;
							std::size_t found = copyArray[0].find_last_of("/");
							output1 = copyArray[0].substr(found+1); //Strip '/' from user input
							userInput = output1;
							
							line1 = "/user/" + userInput;
							
							//Check to see if directory exists
							ifstream driveFile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							if (driveFile.is_open())
							{
								for(int i=0; !driveFile.eof(); i++)
								{
									getline (driveFile,line);
									if (line == line1)
									{
										errorCode = 1;
									}
								}
							}
							driveFile.close();
							
							if (errorCode != 1)
							{
								//Create a drive map file
								ofstream mapfile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt", ios::app);
								if (mapfile.is_open())
								{
									mapfile << "/user/" + userInput << endl;
								}
								mapfile.close();
							
								//Write name of directory to userDir.txt
								ofstream myfile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDir.txt", ios::app);
  								if (myfile.is_open())
 								{
									myfile << userInput << " --- dir --- 0b --- " + timeDate << endl; 
									cout << endl;
									cout << "<< Directory created as /user/" + userInput + " >>"  << endl;
									cout << endl;
								
    							}
    							myfile.close();
							
								//Write the command to oscom.txt
								ofstream myfile1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/oscom.txt", ios::app);
								if (myfile1.is_open())
								{
									myfile1 << "cd.user." << userInput << endl;
									myfile1 << "cd." << userInput << endl;
								}
								myfile1.close();
							
								//Reread oscom.txt and update array
								ifstream com_file1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/oscom.txt");
								if (com_file1.is_open())
								{
									for(int i=0; !com_file1.eof(); i++)
									{
										getline (com_file1,line1);
										osCom[i] = line1;
									}
								}
								com_file1.close();
  							
								//Write directory name to userDirName.txt
								ofstream myfile2 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDirName.txt", ios::app);
								if (myfile2.is_open())
								{
									myfile2 << userInput << endl;
								}
								myfile2.close();
							
								//Load userDir.txt into an array
								ifstream in_file ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDir.txt");
								if (in_file.is_open())
								{
									for(int i=0; !in_file.eof(); i++)
									{
										getline (in_file,line);
										userDir[i] = line;
									}
								}
								in_file.close();
							
								//Create directory text file
								userInput = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + userInput + ".txt";
							
								ofstream openNew ( userInput.c_str() );
								openNew << "  ";
    							openNew.close();
								cout << "Please wait a moment..." << endl;
								msleep(3000);
								driveMenu();
							} else {
								cout << endl;
								cout << "<< Directory already exists!! user/" + userInput + " >>" << endl;
								cout << endl;
								cout << "Please wait a moment..." << endl;
								msleep(3000);
								driveMenu();
							}
							errorCode = 0;
						}
						
						if (userInput == "2")
						{
							//Copy file
							cout << endl;
							cout << "Enter location and filename. '/user/filename.txt'" << endl;
							cout << ">> ";
							cin >> userInput;
							
							copyArray[0] = userInput;
							
							cout << endl;
							cout << "Enter file location to copy too. '/user/Music'" << endl;
							cout << ">> ";
							cin >> userInput;
							
							copyArray[1] = userInput;
							
							//File check
							ifstream userLoad ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							if (userLoad.is_open())
							{
								for(int i=0; !userLoad.eof(); i++)
								{
									getline (userLoad,line);
									if (line == copyArray[0])
									{
										//user1Files[i] = line;
										cout << endl;
										cout << "<< File is good! >>" << endl;
										errorCode += 1;
									}
								}
						    }
							userLoad.close();

							//Check the directory where file is going too
							ifstream userLoad2 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							if (userLoad2.is_open())
							{
								for(int i=0; !userLoad2.eof(); i++)
								{
									getline (userLoad2,line);
									if (line == copyArray[1])
									{
										cout << "<< Destination is good! >>" << endl;
										errorCode += 1;
										
									}
								}
						    }
							userLoad2.close();
							
							//Handle errors
							if (errorCode <= 1) 
							{
								if (errorCode == 0)
								{
									cout << endl;
									cout << "<< Your input was not valid!! >>" << endl;
									cout << endl;
								}
								cout << endl;
								cout << "<< ERROR!!! There were errors in copy! ERROR!!! >>" << endl;
								cout << endl;
								errorCode = 0;
							}
							if (errorCode >= 2)
							{
								//Copy file to new location.
								std::size_t found = copyArray[0].find_last_of("/");
								output1 = copyArray[0].substr(found+1); //File
								if (copyArray[1] != "/user")
								{
									std::size_t found1 = copyArray[1].find_last_of("/");
									output2 = copyArray[1].substr(found1+1); //Path
								} else {
									output2 = "user";
								}
								
								copyArray[4] = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt";
							
								ofstream openCopy ( copyArray[4].c_str() );
								openCopy << output1 + " --- file --- 0b --- " + timeDate << endl;
    							openCopy.close();
							
								ofstream fileMapDir ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt", ios::app);
  								if (fileMapDir.is_open())
 								{
									if (output2 != "user")
									{
										fileMapDir << "/user/" +  output2 + "/" + output1 << endl; 
									} else {
										fileMapDir << "/" +  output2 + "/" + output1 << endl; 
									}
    							}
    							fileMapDir.close();
							
								cout << endl;
								cout << "<< File Copy Success!!! >>" << endl;
								cout << endl;
							}
							cout << "Please wait a moment..." << endl;
							msleep(3000);
							driveMenu();
						}
						if (userInput == "3")
						{
							//Move file
							cout << endl;
							cout << "Enter location and filename. '/user/filename.txt'" << endl;
							cout << ">> ";
							cin >> userInput;
							
							copyArray[0] = userInput;
							
							cout << endl;
							cout << "Enter file location to move file too. '/user/Music'" << endl;
							cout << ">> ";
							cin >> userInput;
							
							copyArray[1] = userInput;
							
							//File check
							ifstream userLoad ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							if (userLoad.is_open())
							{
								for(int i=0; !userLoad.eof(); i++)
								{
									getline (userLoad,line);
									if (line == copyArray[0])
									{
										user1Files[i] = line;
										cout << endl;
										cout << "<< File is good! >>" << endl;
										errorCode += 1;
									}
								}
						    }
							userLoad.close();

							//Check the directory where file is going too
							ifstream userLoad2 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							if (userLoad2.is_open())
							{
								for(int i=0; !userLoad2.eof(); i++)
								{
									getline (userLoad2,line);
									if (line == copyArray[1])
									{
										cout << "<< Destination is good! >>" << endl;
										errorCode += 1;
										
									}
								}
						    }
							userLoad2.close();
							
							//Handle errors
							if (errorCode <= 1) 
							{
								if (errorCode == 0)
								{
									cout << endl;
									cout << "<< Your input was not valid!! >>" << endl;
									cout << endl;
								}
								cout << endl;
								cout << "<< ERROR!!! There were errors in copy! ERROR!!! >>" << endl;
								cout << endl;
								errorCode = 0;
							}
							if (errorCode >= 2)
							{
								//Copy file to new location.
								std::size_t found = copyArray[0].find_last_of("/");
								output1 = copyArray[0].substr(found+1); //File
								if (copyArray[1] != "/user")
								{
									std::size_t found1 = copyArray[1].find_last_of("/");
									output2 = copyArray[1].substr(found1+1); //Path
								} else {
									output2 = "user";
								}
								
								copyArray[4] = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt";
							
								ofstream openCopy ( copyArray[4].c_str() );
								openCopy << output1 + " --- file --- 0b --- " + timeDate << endl;
    							openCopy.close();
							
								ofstream fileMapDir ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt", ios::app);
  								if (fileMapDir.is_open())
 								{
									if (output2 != "user")
									{
										fileMapDir << "/user/" +  output2 + "/" + output1 << endl; 
									} else {
										fileMapDir << "/" +  output2 + "/" + output1 << endl; 
									}
    							}
    							fileMapDir.close();
							
								
							}
							
							//Delete file
							errorCode = 1;

						if (errorCode == 1)
						{
							
							std::size_t found = copyArray[0].find_last_of("/");
							output1 = copyArray[0].substr(0,found); //Path 1st pass
							if (output1 == "user")
							{
								output2 = "user";
							} else {
								std::size_t found1 = output1.find_last_of("/");
								output2 = output1.substr(found1+1); //Path 2nd pass
							}
							std::size_t found2 = copyArray[0].find_last_of("/");
							output1 = copyArray[0].substr(found2+1); //File
							
							//Open driveMap.txt and remove path and filename
							ifstream userMap ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							ofstream tempFile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
							if (userMap.is_open())
							{
								for(int i=0; !userMap.eof(); i++)
								{
									userMap >> line;
									if(line != copyArray[0])
									{
										tempFile << line << endl;
									}
								}
								userMap.close();
								tempFile.close();
								remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
  								rename("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt","/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							}
							
							//Open directory file
							copyArray[4] = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt";
							ifstream userMap1 ( copyArray[4].c_str() );
							ofstream tempFile1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
							if (userMap1.is_open())
							{
								for(int i=0; !userMap1.eof(); i++)
								{
									getline (userMap1,line);
									dirLoc1 = line;
									
									std::size_t found2 = line.find_first_of(" ");
									line1 = line.substr(found2+1); //File
									
									dirLoc = output1 + " " + line1;
									
									if (dirLoc1 != dirLoc)
									{
										tempFile1 << dirLoc1 << endl;
										
									}
								}
								userMap1.close();
								tempFile1.close();
								
								//Remove and rename files
								std::string loc("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt");
								remove(loc.c_str());
								std::string loc1("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
								std::string loc2("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt");
								rename(loc1.c_str() , loc2.c_str());
								
								cout << endl;
								cout << "<< File has been moved!! >>" << endl;
								cout << endl;
							}
						} else {
							cout << endl;
							cout << "File or directory dosn't exist!!" << endl;
							cout << endl;
							errorCode = 0;
						}
							cout << "Please wait a moment..." << endl;
							msleep(3000);
							driveMenu();
							
						}
						if (userInput == "4")
						{
							//Delete file
							cout << endl;
							cout << "Enter filename to be deleted. '/user/filename.txt'" << endl;
							cout << ">> ";
							cin >> userInput;
							
							copyArray[0] = userInput;
							errorCode = 0;
							
							//File check
							ifstream userLoad ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							if (userLoad.is_open())
							{
								for(int i=0; !userLoad.eof(); i++)
								{
									getline (userLoad,line);
									if (line == copyArray[0])
									{
										cout << "<< File is good! >>" << endl;
										errorCode = 1;
									}
								}
						    }
							userLoad.close();
						if (errorCode == 1)
						{
							
							std::size_t found = copyArray[0].find_last_of("/");
							output1 = copyArray[0].substr(0,found); //Path 1st pass
							if (output1 == "user")
							{
								output2 = "user";
							} else {
								std::size_t found1 = output1.find_last_of("/");
								output2 = output1.substr(found1+1); //Path 2nd pass
							}
							std::size_t found2 = copyArray[0].find_last_of("/");
							output1 = copyArray[0].substr(found2+1); //File
							
							//Open driveMap.txt and remove path and filename
							ifstream userMap ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							ofstream tempFile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
							if (userMap.is_open())
							{
								for(int i=0; !userMap.eof(); i++)
								{
									userMap >> line;
									if(line != copyArray[0])
									{
										tempFile << line << endl;
									}
								}
								userMap.close();
								tempFile.close();
								remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
  								rename("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt","/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							}
							
							//Open directory file
							copyArray[4] = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt";
							ifstream userMap1 ( copyArray[4].c_str() );
							ofstream tempFile1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
							if (userMap1.is_open())
							{
								for(int i=0; !userMap1.eof(); i++)
								{
									getline (userMap1,line);
									dirLoc1 = line;
									
									std::size_t found2 = line.find_first_of(" ");
									line1 = line.substr(found2+1); //File
									
									dirLoc = output1 + " " + line1;
									
									if (dirLoc1 != dirLoc)
									{
										tempFile1 << dirLoc1 << endl;
										
									}
								}
								userMap1.close();
								tempFile1.close();
								
								//Remove and rename files
								std::string loc("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt");
								remove(loc.c_str());
								std::string loc1("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
								std::string loc2("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt");
								rename(loc1.c_str() , loc2.c_str());
								
								cout << endl;
								cout << "<< File has been deleted!! >>" << endl;
								cout << endl;
							}
						} else {
							cout << endl;
							cout << "File or directory dosn't exist!!" << endl;
							cout << endl;
							errorCode = 0;
						}
							cout << "Please wait a moment..." << endl;
							msleep(3000);
							driveMenu();
							
							
						}
						if (userInput == "5")
						{
							//Rename a file
							errorCode = 0;
							cout << endl;
							cout << "Enter location and filename. '/user/filename.txt'" << endl;
							cout << ">> ";
							cin >> userInput;
							
							copyArray[0] = userInput;
							
							cout << endl;
							cout << "Enter in new name for file. 'filename.txt'" << endl;
							cout << ">> ";
							cin >> userInput;
							
							copyArray[1] = userInput;
							
							//Check file
							ifstream userLoad ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
							if (userLoad.is_open())
							{
								for(int i=0; !userLoad.eof(); i++)
								{
									getline (userLoad,line);
									if (line == copyArray[0])
									{
										//user1Files[i] = line;
										cout << endl;
										cout << "<< File is good! >>" << endl;
										errorCode = 1;
									}
								}
						    }
							userLoad.close();
							
							//Handle errors
							if (errorCode <= 0) 
							{
								if (errorCode == 0)
								{
									cout << endl;
									cout << "<< Your input was not valid!! >>" << endl;
									cout << endl;
								}
								cout << endl;
								cout << "<< ERROR!!! There were errors in move! ERROR!!! >>" << endl;
								cout << endl;
								errorCode = 0;
							}
							if (errorCode == 1)
							{
								std::size_t found = copyArray[0].find_last_of("/");
								output1 = copyArray[0].substr(0,found); //Path 1st pass
								if (output1 == "user")
								{
									output2 = "user";
								} else {
									std::size_t found1 = output1.find_last_of("/");
									output2 = output1.substr(found1+1); //Path 2nd pass
								}
								std::size_t found2 = copyArray[0].find_last_of("/");
								output1 = copyArray[0].substr(found2+1); //File
							
								//Open driveMap.txt and remove path and filename
								ifstream userMap ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
								ofstream tempFile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
								if (userMap.is_open())
								{
									for(int i=0; !userMap.eof(); i++)
									{
										userMap >> line;
										if(line != copyArray[0])
										{
											tempFile << line << endl;
										}
									}
									userMap.close();
									tempFile.close();
									remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
  									rename("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt","/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
								}
							
								//Open directory file
								copyArray[4] = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt";
								ifstream userMap1 ( copyArray[4].c_str() );
								ofstream tempFile1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
								if (userMap1.is_open())
								{
									for(int i=0; !userMap1.eof(); i++)
									{
										getline (userMap1,line);
										dirLoc1 = line;
									
										std::size_t found2 = line.find_first_of(" ");
										line1 = line.substr(found2+1); //File
									
										dirLoc = output1 + " " + line1;
									
										if (dirLoc1 != dirLoc)
										{
											tempFile1 << dirLoc1 << endl;
										
										}
									}
									userMap1.close();
									tempFile1.close();
								
									//Remove and rename files
									std::string loc("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt");
									remove(loc.c_str());
									std::string loc1("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
									std::string loc2("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt");
									rename(loc1.c_str() , loc2.c_str());
									
									//Write new filename
									std::size_t found = copyArray[0].find_last_of("/");
									output1 = copyArray[0].substr(0,found); //Path 1st pass
									if (output1 == "user")
									{
										output2 = "user";
									} else {
										std::size_t found1 = output1.find_last_of("/");
										output2 = output1.substr(found1+1); //Path 2nd pass
									}
									std::size_t found2 = copyArray[0].find_last_of("/");
									output1 = copyArray[0].substr(found2+1); //File
								
									copyArray[4] = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output2 + ".txt";
							
									ofstream openCopy ( copyArray[4].c_str() );
									openCopy << copyArray[1] + " --- file --- 0b --- " + timeDate << endl;
    								openCopy.close();
							
									ofstream fileMapDir1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt", ios::app);
  									if (fileMapDir1.is_open())
 									{
										fileMapDir1 << "/user/" +  output2 + "/" + copyArray[1] << endl; 
    								}
    								fileMapDir1.close();
								}
							}
							
							cout << endl;
							cout << "<< File has been renamed!! >>" << endl;
							cout << endl;
							
							cout << "Please wait a moment..." << endl;
							msleep(3000);
							driveMenu();
						}
						if (userInput == "6")
						{
							//Format hard drive
							do
							{
								cout << endl;
								cout << "Do you really want to format? (y/n) >> ";
								cin >> userInput;
								if (userInput == "y")
								{
									//format code
									cout << "Are you sure? This will erase everything!" << endl;
									cout << endl;
									cout << "Type 'FORMAT' to erase drive! >> ";
									cin >> userInput;
									if (userInput == "FORMAT")
									{
										//more format code
										cout << endl;
										cout << "<< Formatting drive please wait... >>" << endl;
										msleep(3000);
										//delete driveMap.txt and open the file for write and rebuild
										remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt"); 
										//open driveMap.txt and write system directories
										ofstream driveMap1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt");
										if (driveMap1.is_open())
										{
											driveMap1 << "/user" << endl << "/boot" << endl << "/user/Programs" << endl << "/user/NetFiles" << endl << "/user/Documents" << endl << "/user/copyMe.txt" << endl; //4596 - (code to find later) remove /user/copyMe.txt its used for testing
										}
										driveMap1.close();
										//delete oscom.txt and open the file for write and rebuild
										remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/oscom.txt");
										//open oscom.txt and write system commands
										ofstream oscom1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/oscom.txt");
										if (oscom1.is_open())
										{
											oscom1 << "list" << endl << "cd.boot" << endl << "cd.." << endl << "drive" << endl << "driveMgr" << endl << "read.JsonGuide.txt" << endl << "read.logFile.bin" << endl << "help" << endl;
											oscom1 << "cls" << endl << "net.isp" << endl << "netInfo" << endl << "cd.user" << endl << "read.bbsSystems.txt" << endl << "net.phone.5135211772" << endl << "net.phone.5135212092" << endl;
											oscom1 << "net.phone.5137694213" << endl << "net.phone.5137691827" << endl << "cd.Programs" << endl << "cd.user.Programs" << endl << "cd.Documents" << endl << "cd.user.Documents" << endl;
											oscom1 << "cd.NetFiles" << endl << "cd.user.NetFiles" << endl;
										}
										oscom1.close();
										//delete userDir.txt and not rewrite it. create directory option will write a new file
										remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDir.txt");
										// open userDirNames.txt for input and copy non system directory names to temp file
										ifstream userDirName1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDirName.txt");
										ofstream tempFile1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
										if (tempFile1.is_open())
										{
											for(int i=0; !userDirName1.eof(); i++)
											{
												getline (userDirName1,line);
												if (line == "Programs")
												{
													tempFile1 << line << endl;
												}
												if (line == "Documents")
												{
													tempFile1 << line << endl;
												}
												if (line == "NetFiles")
												{
													tempFile1 << line << endl;
												}
												if (line == "user")
												{
													tempFile1 << line << endl;
												}
											}
										}
										tempFile1.close();
										userDirName1.close();
										//delete files in dirFiles directory
										//use userDirNames.txt to remove files out of dirFiles directory
										ifstream userDirName2 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDirName.txt");
										if (userDirName2.is_open())
										{
											for(int i=0; !userDirName2.eof(); i++)
											{
												getline (userDirName2,line);
												std::string loc("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + line + ".txt");
												remove(loc.c_str());
											}
										}
										//first delete userDirName.txt just to make sure its gone, rename temp.txt to userDirName.txt
										remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDirName.txt");
										rename("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt","/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDirName.txt");
										
										cout << "<< Format complete! >>" << endl;
										
										
										userInput = "n"; //escapes loop, back to menu, guess break(); would work ;)
									} else {
										userInput = "n"; //escapes loop, back to menu, guess break(); would work ;)
									}
								}
								if (userInput == "n")
								{
									// load menu
									cout << endl;
									cout << "Please wait a moment..." << endl;
									msleep(3000);
									driveMenu();
								}
							}while (userInput != "y" && userInput != "n");
							
						}
					} while (userInput != "/exit/");
					
					cout << endl;
					cout << "Exiting Drive Manger..." << endl;
					cout << endl;
					cout << "Unloading from memory..." << endl;
					cout << endl;
					cout << "Please wait a moment... Refreshing screen..." << endl;
					msleep(3000);
					cout << string( 100, '\n' );
					
					promptName = "[C$//]";
				}
				if (userInput == "list")
				{
					if (promptName == "[C$//]")
					{
						cout << endl << dirNames[0];
						cout << endl << dirNames[1] << endl;
						cout << endl << fileNames[5];
						cout << endl << fileNames[0] << endl;
						cout << endl;
					}
					if (promptName == "[C$//boot/]")
					{
						cout << endl << fileNames[1];
						cout << endl << fileNames[2];
						cout << endl << fileNames[3];
						cout << endl << fileNames[4] << endl;
						cout << endl;
					}
					if (promptName == "[C$//user/]")
					{
						cout << endl << dirNames[2];
						cout << endl << dirNames[3];
						cout << endl << dirNames[4];
						cout << endl << dirNames[5];
						cout << endl << fileNames[6] << endl;
						//cout << endl << "";
						
						//User directories
						ifstream myfile5 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDir.txt");
  						if (myfile5.is_open())
 						{
    						while ( getline (myfile5,line) )
    					{
      						cout << line << endl;
    					}
    						myfile5.close();
  						}
						
						//User files
						ifstream user_file ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/user.txt");
  						if (user_file.is_open())
 						{
    						while ( getline (user_file,line) )
    					{
      						cout << line << endl;
    					}
    						user_file.close();
  						}
						cout << endl;
					}
					
					//User created directories
					ifstream myfile4 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDirName.txt");
  					if (myfile4.is_open())
 					{
    					for(int i=0; !myfile4.eof(); i++)
						{
      						getline (myfile4,line);
							if (promptName == "[C$//user/" + line + "/]")
							{
								line1 = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + line + ".txt";
								output1 = line;
								ifstream openIt;
								openIt.open( line1.c_str() );
  								
								if (openIt.is_open())
 								{
    								while ( getline (openIt,line) )
    							{
      								//Checks file size
									streampos begin,end;
									output2 = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/" + output1 + ".txt";
									ifstream fileScan;
									fileScan.open( output2.c_str(),ios::binary);
									begin = fileScan.tellg();
									fileScan.seekg (0, ios::end);
									end = fileScan.tellg();
									fileScan.close();
	
									if ((end-begin) < 5)
									{
										cout << endl;
										cout << "<< Directory is empty! >>" << endl;
									} else {
										
										cout << line << endl;
										
									}
    							}
    							openIt.close();
								cout << endl;
  								}
							}
						}
    				}
    				myfile4.close();
				}
				if (userInput == "read.JsonGuide.txt")
				{
					//Add JsonGuide.txt text here
					cout << endl;
					ifstream userHelpGuide ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/JsonGuide.txt");
							if (userHelpGuide.is_open())
							{
								for(int i=0; !userHelpGuide.eof(); i++)
								{
									getline (userHelpGuide,line);
									cout << line << endl;
								}
						    }
					userHelpGuide.close();
					cout << endl;
					
				}
				if (userInput == "read.bbsSystems.txt")
				{
					//Add bbs phone numbers here
					cout << endl;
					cout << "[1] ... Hell&Chaos Hackers ... (513)521-1772 ... open 24/7" << endl;
					cout << "[2] ... Shareware Shack ...... (513)521-2092 ... open 24/7" << endl;
					cout << "[3] ... Sir-Hacks-A-Lot ...... (513)769-4213 ... open 24/7" << endl;
					cout << "[4] ... Doomsday Cracks ...... (513)769-1827 ... open 24/7" << endl;
					cout << endl;
					
				}
				if (userInput == "net.isp")
				{
					
					cout << endl;
					cout << "Loading..." << endl;
					int choice11 = (rand() % 2000+250);
					msleep(choice11);
					cout << "Running freedomIsp.exe..." << endl;
					int choice12 = (rand() % 2000+250);
					msleep(choice12);
					cout << "Load into memory..." << endl;
					int choice13 = (rand() % 2000+250);
					msleep(choice13);
					cout << "Dialing the isp..." << endl;
					int choice14 = (rand() % 2000+250);
					msleep(choice14);
					cout << "Connected..." << endl;
					int choice15 = (rand() % 2500+1500);
					msleep(choice15);
					
					cout << string( 100, '\n' );
					
					//Load isp welcome screen and menu
					ifstream freedom ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/ispFreedom.txt");
  					if (freedom.is_open())
 					{
    					for(int i=0; !freedom.eof(); i++)
						{
							getline (freedom,line);
							int choice8 = (rand() % 400+100);
							msleep(choice8);
							cout << line << endl;
						}
    					freedom.close();
  					}
  					
					
					promptName = "[net$//modem/]";
					
					do
					{
						cout << promptName;
						cin >> userInput;
					
						if (userInput == "1")
						{
							cout << endl;
							cout << "< E-Mail >" << endl;
							cout << endl;
							cout << "Loading..." << endl;
							int choice16 = (rand() % 2500+1500);
							msleep(choice16);
							cout << string( 100, '\n' );
							
							ifstream freedom1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/emailOptions.txt");
  							if (freedom1.is_open())
 							{
    							for(int i=0; !freedom1.eof(); i++)
								{
									getline (freedom1,line);
									int choice17 = (rand() % 400+100);
									msleep(choice17);
									cout << line << endl;
								}
    							freedom1.close();
								thisData = 1;
  							}
						}
						while (thisData == 1)
						{
							promptName = "[net$//email/]";
							cout << promptName;
							cin >> userInput;
							
						
							if (userInput == "1")
							{
								//Check email option
								cout << endl;
								cout << "< Check E-Mail >";
								cout << endl;
								cout << "Checking..." << endl;
								
								//Check the emailList.txt to see if there is a message
								ifstream emailCheck ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/email/emailList.txt");
								if (emailCheck.is_open())
								{
									for(int i=0; i<1; i++)
									{
										getline (emailCheck,line);
										if (line == "")
										{
											cout << endl;
											cout << "E-Mail is empty!! No new messages!!" << endl;
											cout << endl;
											cout << "Please wait a moment... " << endl;
					                        msleep(3000);
											cout << string( 100, '\n' );
											
											ifstream freedom2 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/emailOptions.txt");
  											if (freedom2.is_open())
 											{
    											for(int i=0; !freedom2.eof(); i++)
												{
													getline (freedom2,line);
													int choice18 = (rand() % 400+100);
													msleep(choice18);
													cout << line << endl;
												}
    											freedom2.close();
  											}
										} else {
											
										do
										{
											
											//Check for message(s) name and print it one by one
											cout << endl;
											cout << "You have messages!!" << endl;
											cout << endl;
											cout << "Message list" << endl;
											cout << "---------------------------" << endl;
											cout << endl;
											
											ifstream message ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/email/emailList.txt");
  											if (message.is_open())
 											{
    											for(int i=0; !message.eof(); i++)
												{
													getline (message,line);
													int choice18 = (rand() % 400+100);
													msleep(choice18);
													cout << line << endl;
												}
    											message.close();
  											}
										
											cout << endl;
											cout << "Type message name to read >> ";
											cin >> userInput;
											cout << endl;
											
											output = "/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/email/" + userInput + ".txt";
											ifstream email ( output.c_str() );
  											if (email.is_open())
 											{
    											for(int i=0; !email.eof(); i++)
												{
													getline (email,line);
													int choice17 = (rand() % 400+100);
													msleep(choice17);
													cout << line << endl;
												}
    											email.close();
  											}
											
											cout << "Would you like to list messages again? (y/n) >> ";
											cin >> userInput;
											
										} while (userInput != "n");
											
											cout << endl;
											cout << "Please wait a moment... " << endl;
					                        msleep(3000);
											cout << string( 100, '\n' );
											
											ifstream freedom3 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/emailOptions.txt");
  											if (freedom3.is_open())
 											{
    											for(int i=0; !freedom3.eof(); i++)
												{
													getline (freedom3,line);
													int choice19 = (rand() % 400+100);
													msleep(choice19);
													cout << line << endl;
												}
    											freedom3.close();
  												}
											}
										}
										emailCheck.close();
										} 
									} 
						
						if (userInput == "2")
						{
							//Send email
							
							//Create key file for email
							for (int i = 0; i<1; i++)
							{
								ofstream out_file12 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/scramble.txt", ios::app);
								ifstream com_file12 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/abc123.txt");
								if (com_file12.is_open())
								{
									for(int i=0; !com_file12.eof(); i++)
									{
										getline (com_file12,line1);
										out_file12 << line1;
									}
								}
								com_file12.close();
								out_file12.close();
	
								ifstream com_file11 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/scramble.txt");
								if (com_file11.is_open())
								{
									getline (com_file11,line1);
									copyArray[0] = line1;
								}
								com_file11.close();
								remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/scramble.txt");
	
								//int choice = (rand() % 104); 
	
								string theWord = copyArray[0];
								string jumble = theWord; 
								int length = jumble.size(); 
	
								for (int i = 0; i < length; ++i) 
								{ 
									int index1 = (rand() % length); 
									int index2 = (rand() % length); 
									char temp = jumble[index1]; 
									jumble[index1] = jumble[index2]; 
									jumble[index2] = temp; 
								}
	
								ofstream out_file11 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/keyFile.txt");
								if (out_file11.is_open())
								{
									out_file11 << jumble << endl;
								}
								out_file11.close();
							}
	
							ifstream com_file10 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/keyFile.txt");
							if (com_file10.is_open())
							{
								getline (com_file10,line);
							}
							com_file10.close();
	
							int choice28 = (rand() % 25+15);
							newLineChecker = choice28;
	
							ofstream out_file10 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/keyFile.txt");
							if (out_file10.is_open())
							{
								for (int i=0; i != line.size(); i++)
								{
									if (i == newLineChecker)
									{
										newLineChecker += choice28;
										out_file10 << endl;
									}
			
									out_file10 << line[i];
								}
							}
								
							ifstream keyIn ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/keyFile.txt");
							if (keyIn.is_open())
							{
								getline (keyIn,line);
							}
							keyIn.close();
							remove ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/keyFile.txt");
								
							//User input for email
							cout << endl;
							cout << "Enter email address: ";
							cin >> userInput;
							cout << endl;
							cout << "Type '<EOF>' to exit email writing" << endl;
							cout << endl;
	
							do
							{
								cout << "Line[" << lineOut << "]>> ";
								cin.getline (line3,256);
		
								ofstream email_file ("/storage/emulated/0/MyGame/myHackGame/jni/gameFiles/email/emailSend.txt",ios::app);
								if (email_file.is_open())
								{
									if (lineOut == 1)
									{
										email_file << ">> From <<" << endl;
										email_file << myAddy << endl;
										email_file << ">> To <<" << endl;
										email_file << userInput << endl;
										email_file << ">> Key <<" << endl;
										email_file << line << endl;
										email_file << "----------------------------------------------" << endl;
										email_file << "<>" << endl;
									}
									email_file << line3 << endl;
								}
								email_file.close();
								lineOut ++;
							} while (strcmp (line3,exit) !=0);
							
							while ((userInput != "y") && (userInput != "n"))
							{
								cout << endl;
								cout << "Would you like to preview message before send? (y/n) >> " << endl;
								cin >> userInput;
							}
	
							if (userInput == "n")
							{
								cout << endl;
								cout << endl << "Message sent!!";
								cout << endl;
							}
	
							if (userInput == "y")
							{
								
								//Preview email and print to screen
								ifstream email_file1 ("/storage/emulated/0/MyGame/myHackGame/jni/gameFiles/email/emailSend.txt");
								if (email_file1.is_open())
								{
									for(int i=0; !email_file1.eof(); i++)
									{
										getline (email_file1,output);
										int choice28 = (rand() % 400+100);
										msleep(choice28);
										cout << output << endl;
									}
								} email_file1.close();
								userInput = "";
								while ((userInput != "y") && (userInput != "n"))
								{
									cout << "Send message? (y/n) >> ";
									cin >> userInput;
								}
		
								if (userInput == "y")
								{
									cout << endl;
									cout << "Message sent!!";
									cout << endl;
								}
								if (userInput == "n")
								{
									cout << endl;
									cout << "<< Message canceled >>" << endl;
									cout << endl;
								}
							} 
	
							//Program to delete text file here.
							
							cout << "Please wait a moment... " << endl;
					        msleep(3000);
							cout << string( 100, '\n' );
											
							ifstream freedom4 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/emailOptions.txt");
  							if (freedom4.is_open())
 							{
    							for(int i=0; !freedom4.eof(); i++)
								{
									getline (freedom4,line);
									int choice20 = (rand() % 400+100);
									msleep(choice20);
									cout << line << endl;
								}
    							freedom4.close();
							}
						}
						if (userInput == "3")
						{
							//Delete email
							cout << endl;
							cout << "Message list" << endl;
							cout << "---------------------------" << endl;
							cout << endl;
							
							ifstream message1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/email/emailList.txt");
  							if (message1.is_open())
 							{
    							for(int i=0; !message1.eof(); i++)
								{
									getline (message1,line);
									int choice21 = (rand() % 400+100);
									msleep(choice21);
									cout << line << endl;
								}
    							message1.close();
  							}
							
							cout << endl;
							cout << "Type message name to delete >> ";
							cin >> userInput;
							cout << endl;
							
							//Open emailList.txt and remove path and filename
							ifstream emailMap ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/email/emailList.txt");
							ofstream emailTemp ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt");
							if (emailMap.is_open())
							{
								for(int i=0; !emailMap.eof(); i++)
								{
									getline(emailMap,line);
									if(line != userInput)
									{
										emailTemp << line << endl;
									}
								}
								remove("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/email/emailList.txt");
  								rename("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/temp.txt","/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/email/emailList.txt");
							}
							emailMap.close();
							emailTemp.close();
							
							cout << endl;
							cout << "Message has been deleted!!" << endl;
							cout << endl;
							
							cout << "Please wait a moment... " << endl;
					        msleep(3000);
							cout << string( 100, '\n' );
											
							ifstream freedom4 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/emailOptions.txt");
  							if (freedom4.is_open())
 							{
    							for(int i=0; !freedom4.eof(); i++)
								{
									getline (freedom4,line);
									int choice20 = (rand() % 400+100);
									msleep(choice20);
									cout << line << endl;
								}
    							freedom4.close();
  							}
						}
						if (userInput == "4")
						{
							cout << endl;
							cout << "Please wait a moment... " << endl;
					        msleep(3000);
							
							cout << string( 100, '\n' );
					
							//Load isp welcome screen and menu
							ifstream freedom ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/ispFreedom.txt");
  							if (freedom.is_open())
 							{
    							for(int i=0; !freedom.eof(); i++)
								{
									getline (freedom,line);
									int choice8 = (rand() % 400+100);
									msleep(choice8);
									cout << line << endl;
								}
    							freedom.close();
  							}
							thisData = 0;
						} 
					}

					} while (userInput != "term");
					
					cout << endl;
					cout << "Exiting net connection..." << endl;
					int choice16 = (rand() % 2000+250);
					msleep(choice16);
					cout << "Disconnecting phone connection..." << endl;
					int choice17 = (rand() % 2000+250);
					msleep(choice17);
					cout << "Unload from memory..." << endl;
					int choice18 = (rand() % 2000+250);
					msleep(choice18);
					cout << endl;
					cout << "Please wait a moment... Refreshing screen... " << endl;
					msleep(3000);
					cout << string( 100, '\n' );
					
					promptName = "[C$//]";
					
				}
				if (userInput == "net.phone.5135211772")
				{
					
					//Hell&Chaos Hackers bbs system
					cout << string( 100, '\n' );
					
					cout << "Clear buffers..." << endl;
					int choice = (rand() % 2000+250);
					msleep(choice);
					cout << "Loading drivers..." << endl;
					int choice1 = (rand() % 2000+250);
					msleep(choice1);
					cout << "Load into memory..." << endl;
					int choice2 = (rand() % 2000+250);
					msleep(choice2);
					cout << "Calling number 5135211772..." << endl;
					int choice3 = (rand() % 2000+250);
					msleep(choice3);
					cout << "Signal recieved..." << endl;
					int choice4 = (rand() % 2000+250);
					msleep(choice4);
					cout << "Connecting at 4800bps..." << endl;
					int choice5 = (rand() % 2000+250);
					msleep(choice5);
					cout << "Logging in..." << endl;
					int choice6 = (rand() % 2000+250);
					msleep(choice6);
					cout << endl;
					
					//Load the welcome screen for hell&chaos
					ifstream myfile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/Hell&ChaosWelcome.txt");
  					if (myfile.is_open())
 					{
    					for(int i=0; !myfile.eof(); i++)
						{
							getline (myfile,line);
							int choice8 = (rand() % 400+100);
							msleep(choice8);
							cout << line << endl;
						}
    				}
					myfile.close();
					
					promptName = "[net$//modem/]";
					
					do
					{
						cout << promptName;
						cin >> userInput;
					
						if (userInput == "1")
						{
							cout << "menu selection 1" << endl;
						}
						if (userInput == "2")
						{
							cout << "menu selection 2" << endl;
						}
						if (userInput == "3")
						{
							cout << "menu selection 3" << endl;
						}
						if (userInput == "4")
						{
							cout << "menu selection 4" << endl;
						}
						if (userInput == "5")
						{
							//Download files
							do
							{
								cout << endl;
								cout << "One moment please... " << endl;
								msleep(3000);
								cout << string( 100, '\n' );
							
								ifstream fileList ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/hell&chaosFiles.txt");
  								if (fileList.is_open())
 								{
    								for(int i=0; !fileList.eof(); i++)
									{
										getline (fileList,line);
										int choice26 = (rand() % 400+100);
										msleep(choice26);
										cout << line << endl;
									}
  								}
								fileList.close();
							
								int choice35 = (rand() % 400+100);
								msleep(choice35);
								cout << "Enter filename to download or '/menu/' to return." << endl;
								cout << "Download >> ";
								cin >> userInput;
							
								ifstream hellFile ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/downloadFiles.txt");
								if (hellFile.is_open())
								{
									for(int i=0; !hellFile.eof(); i++)
									{
										hellFile >> copyArray[0] >> copyArray[1];
										if (copyArray[0] == userInput)
										{
											break;
										}
									}
								}
								hellFile.close();
							
								if (userInput == copyArray[0])
								{
									cout << endl;
								
									int choice29 = (rand() % 400+100);
									msleep(choice29);
									cout << "Starting download..." << endl;
									cout << "Download to /user/NetFiles/" << copyArray[0] << endl;
									cout << endl;
								
									int value = atoi(copyArray[1].c_str()); 
									fileSize = value; //Set file size
									speedReduce = bpsModem *.75;
									result = (fileSize / speedReduce); //Set download bps
									//Convert seconds into seconds, minutes, hours
									if (result < 60)
									{
										int choice30 = (rand() % 400+100);
										msleep(choice30);
										cout << "ETA - " << result << " second(s)" << endl;
									}
									if (result >= 60)
									{
										downloadTime = result / 60;
										if (downloadTime < 60)
										{
											downloadTime1 = result - (downloadTime * 60);
											int choice31 = (rand() % 400+100);
											msleep(choice31);
											cout << "ETA - " << downloadTime << " minute(s) " << downloadTime1 << " second(s)" << endl;
										}
										if (downloadTime >= 60)
										{
											hour = downloadTime / 60;
											//hour = downloadTime1 / 60;
											minute = downloadTime - (hour * 60);
											second = result - (downloadTime * 60);
											int choice32 = (rand() % 400+100);
											msleep(choice32);
											cout << "ETA - " << hour << " hour(s) " << minute << " minute(s) " << second << " second(s)" << endl;
										}
									}
									//Start download progress
									cout << endl;
									int choice33 = (rand() % 400+100);
									msleep(choice33);
									cout << "  -- Download Started --" << endl;
									cout << "[" << std::flush;
									result = 1000 * (result / 20); //Convert result to miliseconds
									ifstream com_file ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/progressBar.txt");
									if (com_file.is_open())
									{
										for(int i=0; !com_file.eof(); i++)
										{
											getline (com_file,line);
											msleep(result);
											cout << line << std::flush; //Need flush for same line output.
										}
									}
									com_file.close();
							
									ofstream netFiles("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/dirFiles/NetFiles.txt",ios::app);
  									if (netFiles.is_open())
 									{
    									netFiles << copyArray[0] << " --- file --- " << copyArray[1] << " --- " + timeDate << endl;
  									}
									netFiles.close();
							
									ofstream netFiles1("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/driveMap.txt",ios::app);
  									if (netFiles1.is_open())
 									{
    									netFiles1 << "/user/NetFiles/" << copyArray[0] << endl;
  									}
									netFiles1.close();
							
									cout << "]";
									int choice34 = (rand() % 400+100);
									msleep(choice34);
									cout << endl << "  -- Download Complete --" << endl;
									while ((userInput != "y") && (userInput != "n"))
									{
										cout << endl;
										cout << "Download more files? (y/n) >> ";
										cin >> userInput;
									}
							
									if (userInput == "y")
									{
										//Reloop
									}
							
									if (userInput == "n")
									{
										userInput = "/menu/";
									}
								}
							} while (userInput != "/menu/");
							
							cout << endl;
							cout << "One moment please... " << endl;
							msleep(3000);
							cout << string( 100, '\n' );
								
							ifstream myFile1 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/Hell&ChaosWelcome.txt");
  							if (myFile1.is_open())
 							{
    							for(int i=0; !myFile1.eof(); i++)
								{
									getline (myFile1,line);
									int choice35 = (rand() % 400+100);
									msleep(choice35);
									cout << line << endl;
								}
    						}
							myFile1.close();
						}
						if (userInput == "6")
						{
							cout << "menu selection 6" << endl;
						}
					
					} while (userInput != "term");
					cout << endl;
					cout << "Exiting net connection..." << endl;
					int choice8 = (rand() % 2000+250);
					msleep(choice8);
					cout << "Disconnecting phone connection..." << endl;
					int choice9 = (rand() % 2000+250);
					msleep(choice9);
					cout << "Unload from memory..." << endl;
					int choice10 = (rand() % 2000+250);
					msleep(choice10);
					cout << endl;
					cout << "Please wait a moment... Refreshing screen... " << endl;
					msleep(3000);
					cout << string( 100, '\n' );
					
					promptName = "[C$//]";
					
				}
				
				//Change directory to user created directories
				ifstream myfile3 ("/storage/emulated/0/MyGame/MyHackGame/jni/gameFiles/userDirName.txt");
  				if (myfile3.is_open())
 				{
    				for(int i=0; !myfile3.eof(); i++)
					{
      					getline (myfile3,line);
						if (userInput == "cd.user." + line)
						{
							if (promptName == "[C$//user/" + line + "/]")
							{
								
							} else {
								promptName = "[C$//user/" + line + "/]";
								dirChange++;
							}
						}
						if (userInput == "cd." + line)
						{
							if (promptName == "[C$//user/]")
							{
								promptName = "[C$//user/" + line + "/]";
								dirChange++;
							}
						}
					}
    			}
    			myfile3.close();
				if (userInput == "cd.boot")
				{
					promptName = "[C$//boot/]";
				}
				if (userInput == "cd.user")
				{
					promptName = "[C$//user/]";
				}
				if (userInput == "cd..")
				{
					if (dirChange >= 1)
					{
						promptName = "[C$//user/]";
						dirChange = 0;
					} else {
						promptName = "[C$//]";
					}
				}
			}
		}
	} while (userInput != "exit");
	cout << endl << "System Shutdown In Progress...";
  
	return 0;
}
