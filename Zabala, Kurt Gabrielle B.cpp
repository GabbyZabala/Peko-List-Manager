#include <iostream>
#include <list> // list command
// add on ko lang to sir hehe - kurt
#include <windows.h>// windows command
#include <conio.h>    // For _kbhit() and _getch()
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

bool dev_mode = false;//for debugging purposes

struct Sys_function{
	int locale = 1;
	string str_log(int num){
		string coms;
		switch (num){
			case 1:
				coms += "i think my creator just watch cinnamoroll.. huhu";break;
			case 3:
				coms += "\" shaddup b$#@! \" -pekora XD";break;
			case 5:
				coms +="vHA!<HA!^HA!>HA! peko?";break;
			case 7:
				coms += "wazzpu what you want?";break;
			default:
				coms +="hello! what can i do for you? purr~ purr~";break;
		}
		return coms;
	}
	string err_log(int num){
		string coms;
		switch (num){
			case 1:
				coms += "I didnt hear you clearly???";break;
			case 3:
				coms += "what?";break;
			case 5:
				coms +="eh?";break;
			case 7:
				coms += "pardon?";break;
			default:
				coms +="im please choose on the choices";break;
		}
		return coms;
	}
	void animation(string input){
		for (int i = 0; i < input.length(); ++i) {
        	cout << input[i] << flush;
        	Sleep(10); // Adjust the delay in milliseconds
    	}
	}	
}fcn;

struct GUI_Function{
	string eye[3] = {"0w0","UwU","-u-"};
	void header(){// heaeder indecator optional XDDD
		cout<<"Prototype 1.0.3\t\t stats:"<<rand()<<endl;//version used
	}
	int randomNum(int max_num){// random shit number using time and some shit
		int ran_num;
		srand(static_cast<unsigned>(time(0)));
		ran_num = (rand() % max_num) + 1;
		return ran_num;
	}
	void peko(){
		string pekora;
		srand(static_cast<unsigned>(time(0)));
	    int ran_num = (rand() % 3) + 1;
		pekora += " n_n\n";							//" n_n"
		pekora += "( " + eye[ran_num-1] + ")\n";	//"( 0w0)"
		pekora += "/ >< \\\n";						//"/ >< |"
		cout<<pekora;						
	}
	void start_menu (){
		int siso = 0;
	    while (!_kbhit()) {
	    	header();
	        cout << "\n\n\n\n\t\tWelcome to Task Manager\n\n\n\t";
	        if (siso == 0) {
                cout << "Press any key to start....";
                siso++;
            } else {
                cout << " "; 
                siso--;
            }	
	        cout<<"\n";
	        peko();
			Sleep(1000);  
	        system("cls"); 
	    }
	    _getch();  
	}
	void loading(int partialDuration){
		int per = 100;
		int load = 0;
		bool preset = true;
		while(true){
			system("cls");
			header();
		//	  n_n
		//  (,*-*,)
		//	|-U U---------------------------------------------|
		//  |
			cout<<"\n\n  n_n\n(,*-*,)\tLOADING...\n";   
			cout<<"+=U U================================================================================================+\n|";
			for(int i = 1; i <= load; i++)	cout<<"*";
			for(int x = 1; x <= per; x++)	cout<<" ";
			cout<<"|\n";
			cout<<"+====================================================================================================+";
			if(!preset) {
				cout<<"\n\n\t";
				break;
			}
			load = load + randomNum(partialDuration);
			per = 100 - load;
			if(load >= 100){
				load = 100;
				per = 0;
				preset = false; 
			}
			sleep(1);
		}
	}
	string reference_point(int frame){
		string lan;
		switch (frame){
			case 1:
				lan += "\t ________________________________________________________________\n";
				break;
			case 2:
				lan += " n_n	 |\n";
				lan += "( " + eye[randomNum(3)-1] + ")  /\t";//add font start here
				break;
			case 3:
				lan +="/ >< |  \\\t";
				break;
			case 4:
				lan +="\t |\t";//repeated add functions
				break;
			case 5:
				lan += "\t |________________________________________________________________\n";
				break;
			default:
				lan += "[--No Reference is recorded in this frame--]";
				break;			
		}
		return lan;
	}
}display;

struct Compile{
	Sys_function fcn_C;
	GUI_Function gui_C;
	bool list_on_main = false;
	bool undersato = true;
	list<string> real_list;
	void main_menu(int error){
		string main[5] = {"[ 1 ] DISPLAY TASKS","[ 2 ] ADD TASK","[ 3 ] REMOVE TASK","[ 4 ] CLEAR TASK","[ 5 ] EXIT"};
		cout<<gui_C.reference_point(1);
		if(list_on_main){
			display_task_opt();
		}
		if(error>= 1)	cout<<gui_C.reference_point(2)<<fcn_C.err_log(gui_C.randomNum(8));
		else			cout<<gui_C.reference_point(2)<<fcn_C.str_log(gui_C.randomNum(8));
		cout<<endl;
		cout<<gui_C.reference_point(3)<<endl;
		for(int i = 0; i<= 4; i++)cout<<gui_C.reference_point(4)<<main[i]<<"\n"<<gui_C.reference_point(4)<<endl;
		cout<<gui_C.reference_point(5);
	}
	void point_exit(int error){
		cout<<gui_C.reference_point(1);
		cout<<gui_C.reference_point(2);
		if(error>= 1)	fcn_C.animation(" oh your going now? ok farewell huhu!!");	
		else			cout<<fcn_C.str_log(gui_C.randomNum(8));
		cout<<endl;
		cout<<gui_C.reference_point(3)<<endl;
		cout<<gui_C.reference_point(4)<<endl;
		cout<<gui_C.reference_point(5);
	}
	void add_list_phase(int error){
		string main[3] = {"[ 1 ] URGENT TASK", "[ 2 ] LOW PRIORITY TASK", "[ 3 ] CANCEL"};
		cout<<gui_C.reference_point(1);
		cout<<gui_C.reference_point(2);
		if(error >= 1) 	cout<<fcn_C.err_log(gui_C.randomNum(8));
		else		cout<<"What type of task you want to add right now?";
		cout<<endl;
		cout<<gui_C.reference_point(3)<<endl;
		for(int i = 0; i <= 2; i++) cout<<gui_C.reference_point(4)<<main[i]<<"\n"<<gui_C.reference_point(4)<<endl;
		cout<<gui_C.reference_point(5);
	}
	void task_query_add(int type){
		string main[2] = {"TASK NAME", "SUBJECT"};
		string lab[2];
		string complete_task_name;
		cout<<gui_C.reference_point(1);
		cout<<gui_C.reference_point(2);
		cout<<"Pls input the following";
		cout<<endl;
		cout<<gui_C.reference_point(3)<<endl;
		for(int i = 0; i <= 1; i++) {
			string input;
			cout<<gui_C.reference_point(4)<<main[i]<<": ";
			getline(cin, input);
			lab[i] = input;
			cout<<gui_C.reference_point(4)<<endl;
		}
		cout<<gui_C.reference_point(5);
		fcn_C.animation("\tSaving task.");
		for(int y = 0; y <= 1; y++){
			complete_task_name += lab[y] + "\t";
			cout<<".";
			sleep(1);
		}
		switch(type){
			case 1:
				real_list.push_front(complete_task_name);
				fcn_C.animation("Added as Urgent task");
				break;
			case 2:
				real_list.push_back(complete_task_name);
		}
	}
	void display_task_opt(){
		string detail[3] = {"NO.","TASK NAME","DETAILS" };
		cout<<gui_C.reference_point(4);
		for(int i = 0; i<=2;i++) cout<<detail[i]<<"\t";
		cout<<endl;
		if(real_list.size() != 0 ){
			int num = 1;
			for (const auto& item : real_list) {
	    		cout<<gui_C.reference_point(4)<<"[ "<<num<<" ]\t"<<item <<endl;
	    		num++;
			}
		}
		else
			cout<<gui_C.reference_point(4)<<"[* NO TASK IS RECORDED *]"<<endl;
		cout<<gui_C.reference_point(4)<<endl;
	}
	void display_task_all(){
		cout<<gui_C.reference_point(1);
		cout<<gui_C.reference_point(2);
		if(real_list.size() != 0)
			cout<<"Here's the task you input..";
		else
			cout<<"it seems you still havent input a task yet..";
		cout<<endl;
		cout<<gui_C.reference_point(3)<<endl;
		display_task_opt();
		if(gui_C.randomNum(2) == 2) cout<<gui_C.reference_point(4)<<"//type '*' on the command so you can view the task on MAIN MENU"<<endl;
		cout<<gui_C.reference_point(5);
		cout<<"\t";system("pause");
	}
	void clear_all_task(bool question){
		if(question){
			cout<<gui_C.reference_point(1);
			cout<<gui_C.reference_point(2);
			if(real_list.size() != 0){
				cout<<"Removing all task...";
				fcn_C.animation("...Complete");
				real_list.clear();
			}
			else
				cout<<"No Task is recorded so no Data is removed...";
			cout<<endl;
			cout<<gui_C.reference_point(3)<<endl;
			cout<<gui_C.reference_point(4)<<endl;
			cout<<gui_C.reference_point(5);
			cout<<"\t";system("pause");
		}
		else {	
			string lan[2] = {"[ 1 ] YES", "[ 2 ] NO"};
			cout<<gui_C.reference_point(1);
			cout<<gui_C.reference_point(2)<<"Are you sure you want to clear your task?"<<endl;
			cout<<gui_C.reference_point(3)<<"this action is not reversable.."<<endl;
			for(int i = 0; i <= 1; i++)	cout<<gui_C.reference_point(4)<<"\n"<<gui_C.reference_point(4)<<lan[i]<<endl;
			cout<<gui_C.reference_point(5);
		}
	}
	bool remove_task(){ //display for remove
		int num = 1;
		cout<<gui_C.reference_point(1);
		cout<<gui_C.reference_point(2);
		if(real_list.size() != 0){
			cout<<"Which task you want to remove?..."<<real_list.size();	
		}else{
			cout<<"it seems you still havent input a task yet..";
		}
		cout<<endl;
		cout<<gui_C.reference_point(3)<<endl;
		if(real_list.size() != 0){
			for (const auto& item : real_list)	{
				cout<<gui_C.reference_point(4)<<"[ "<<num<<" ] "<<item<<"\n"<<gui_C.reference_point(4)<<endl;	
				num++;
			}
		}
		cout<<gui_C.reference_point(5);
		cout<<"\t";	system("pause");
		if(real_list.size() != 0){
			return undersato = false;
		}
		else return undersato = true;
	}
	void remove_function(int remove_number){//remove function because i want too XD
		string storage[real_list.size()];
		int lan = real_list.size();
		int y = 0, l=0;
		for (const auto& item : real_list) {
	    		storage[y] = item;
				y++;
		}
		if(dev_mode){
			cout<<"before: "<<real_list.size()<<endl;
			cout<<"B-RE:"<<remove_number<<endl;
		}
		real_list.clear();
		if(lan>= 1){
			for(int i = 0; i < y ;i++){
				if(i != remove_number){
					if(dev_mode)cout<<"\t-"<<storage[i]<<endl;
					real_list.push_back(storage[i]);
				}else{
					if(dev_mode)cout<<"\t!>"<<storage[i]<<endl;
				}
				l = i;
			}
			
		}
		if(dev_mode){
			cout<<"after: "<<real_list.size()<<endl;
			cout<<"A-RE:"<<remove_number<<endl;
			cout<<"I: "<<l<<endl;
			cout<<"recheck: "<<real_list.size()<<endl;
			system("pause");
		}
	}
}cp;

int main (){
	display.start_menu();
	display.loading(50);
	//system("pause");	//testing purposes
	int error = 0;int list_on_main_data = cp.list_on_main;
	string face[6] = {"( 0w0 )", "( ~w~ )", "( \"w\" )", "( T-T )", "( *u* )", "( ~-~ )"};
	int add_stat = 0;
	int rev_num = 0;//
	bool add = false,clear = false,ene = false ;
	while(true){
		rebot:
		string command;
		char com_lan;
		system("cls");
		display.header();
		switch(fcn.locale){
			case 1:
				cp.main_menu(error);
				break;
			case 2:
				cp.display_task_all();
				fcn.locale = 1;
				goto rebot;
				break;
			case 3:
				cp.add_list_phase(error);
				break;
			case 4://remove a task
				cp.remove_task();
				if(!cp.undersato){
					fcn.locale = 7;
				}else{
					fcn.locale = 1;
					goto rebot;
				}
				break;
			case 5://clear task
				cp.clear_all_task(ene);
				if(ene){
					fcn.locale = 1;
					ene = false;
					clear = false;
					goto rebot;
				}
				break;
			case 6:
				cp.point_exit(error);
				sleep(1);
				system("cls");
				display.loading(20);
				return 0;
			case 7:
				cp.remove_function(rev_num-1);
				fcn.locale = 1;
				goto rebot;
				break;
			case 8://add task
				cp.task_query_add(add_stat);
				fcn.locale = 1;
				sleep(2);
				goto rebot;
				break;
			default:
				break;
		}
		cout<<"\n\n\t:";
		getline(cin,command);
		com_lan = command[0];
		if(fcn.locale == 7){
			try {// Check if the character is a digit
    		    if (isdigit(command[0])){
					rev_num = (command[0] - '0');  // Convert '1' to 1 
	    	    }else{ 			   	        
					throw invalid_argument("Non-numeric character input");
		    	}
			}
		    catch (const invalid_argument& e) {fcn.locale = 4; }
    		goto rebot;
		}
		fcn.animation("\n\t-------------------------\n"+face[display.randomNum(5)]+": ");
		switch(com_lan){
			case '1':
				if(add || clear){
					if(add){					
						fcn.animation("this one is a urgent one");
						add_stat = 1;
						fcn.locale = 8;
						add = false;
					}
					if(clear){
						fcn.animation("aight do it");
						ene = true;
					}
				}
				else{
					fcn.animation("can I see the TASK?\n\n");
					fcn.locale = 2;
				}
				error = 0;break;
			case '2':
				if(add || clear){
					if(add){
						fcn.animation("you can add this one on the end huhu....");
						add_stat = 2;
						fcn.locale = 8;
						add = false; 
					}
					if(clear){
						fcn.animation("nevermind, just keep it at the moment..");
						fcn.locale = 1;
						clear = false;
					}
				}
				else{
					fcn.animation("I\'ll would like to add a TASK\n\n");
					add = true;
					fcn.locale = 3;
				}
				error = 0;break;
			case '3':
				if(add){
					fcn.animation("I change my mind");
					fcn.locale = 1;
					add = false;
				}
				else{
					fcn.animation("I would like to remove a TASK\n\n");
					fcn.locale = 4;
				}
				error = 0;break;
			case '4':
				if(!add){
					fcn.animation("can you clear my TASK?\n\n");
					clear = true;
					fcn.locale = 5;
					error = 0;break;
				}
			case '5':
				if(!add){
					fcn.animation("I think i gotta go\n\n");
					fcn.locale = 6;
					break;
				}
			case '*':
				fcn.animation("prompt chmod /data_processing/show/action?="+ to_string(list_on_main_data) );
				if(!cp.list_on_main)	cp.list_on_main = true;
				else				cp.list_on_main = false;
				break;
			default:
				fcn.animation("i-....");
				error++;
				break;
		}
		Sleep(100);
		
	}
	return 0;
}