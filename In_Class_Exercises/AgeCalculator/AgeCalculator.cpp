#include <iostream> 
	
	using namespace std; 
	
	int main() 
	{ 
		int year_now, age_now, another_year, another_age, born_y, born_m,
		  month_now, another_month, diff_m, diff_m2; 
	 
		cout << "Enter the current year then press RETURN.\n"; 
		cin >> year_now; 
		
		cout<< "Enter the current month (a number from 1 to 12).\n";
		cin>> month_now;
		

		
		cout << "Enter your current age in years.\n"; 
		cin >> age_now; 
		
		cout <<"Enter the month in which you where born  (a number from 1 to 12) : \n";
		cin>> born_m;

	 
		cout << "Enter the year for which you wish to know your age.\n";
		cin >> another_year; 
		
		cout<<"Enter the month in this year \n";
		cin >> another_month;

	      	if(month_now > 12 || month_now<1 || born_m<1 || born_m>12 ||another_month<1 || another_month>12){
		  cout<< "Big bad Fatal Error : Program terminated. \n";
		  return 0;
		}
	 
		another_age = another_year - (year_now - age_now); 
		diff_m = month_now - born_m ;
	 
		if (another_age >= 0 && another_age<150) {
		  if(another_age == 0 && diff_m < 0){
		    cout<<"You weren't even  born yet!.\n";
		    return 0;
		  }

		  if(diff_m>=0){
		      born_y= year_now - age_now ;
		  }else{
		    born_y=year_now-age_now-1;
		  }
		  diff_m2 = another_month-born_m;
		  another_age =another_year - born_y;
		  
		  if(diff_m2>=0 && diff_m2 == 1){
		  	cout << "Your age in " <<another_month<<"/"<< another_year << ": "; 
		      	cout << another_age << "year(s) and "<< diff_m2<< "month"<< "\n";
		  }else if(diff_m2>=0){
			cout << "Your age in " <<another_month<<"/"<< another_year << ": "; 
		      	cout << another_age << "year(s) and "<< diff_m2<< "months"<< "\n";
		  }else if(diff_m2<0 && diff_m2 == 1){
		  	cout << "Your age in " <<another_month<<"/"<< another_year << ": "; 
		      	cout << another_age - 1  << "year(s) and "<< 12+ diff_m2<< "month"<< "\n";
		  }else {
			cout << "Your age in " <<another_month<<"/"<< another_year << ": "; 
		      	cout << another_age -1 << "year(s) and "<< 12 + diff_m2 <<"months"<< "\n";
		  }
		} else if (another_age<0) { 
			cout << "You weren't even born in ";
			cout << another_year << "!\n"; 
		} else  {
			cout<< "Sorry, you will probably be dead by year "
			<< another_year << endl;
		}
	
		return 0; 
	}

