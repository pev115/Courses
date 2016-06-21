#include <iostream>
	using namespace std;
	
	enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
	
	int closing_time(Day day_of_the_week);

	void print_day(Day the_day, ostream& o_s);

	/* MAIN PROGRAM */
	int main()
	{
		int count;
	
                cout.setf(ios::left);
		/* Print table heading */
		cout.width(17);
		cout << "DAY";
		cout << "CLOSING TIME\n\n";
		

		/* Print table from Sunday to Saturday */
		for (count = static_cast<int>(Sun); count <= static_cast<int>(Sat); count++)
		{
		  
			cout.width(19);
			print_day(static_cast<Day>(count), cout);
			
			cout << closing_time(static_cast<Day>(count)) << "pm\n";
		}
		return 0;
	}
	/* END OF MAIN PROGRAM */
	
	/* FUNCTION TO GENERATE SHOP CLOSING TIMES FROM DAY OF THE WEEK */
	int closing_time(Day day_of_the_week)
	{
		switch(day_of_the_week)
					{
					case Sun: return 1; break;
					case Mon: 
					case Thu: 
					case Fri:
					case Tue: return 6; break;
					case Wed: return 8; break;
					case Sat: return 5; break;
					default : return 9;
					}
					
	}


	/*FUNCTION TO PRINT*/
	
	void print_day(Day the_day, ostream& o_s){

	switch (the_day)
			{
				case Sun: o_s << "Sunday"; break;
				case Mon: o_s << "Monday"; break;
				case Tue: o_s << "Tuesday"; break;
				case Wed: o_s << "Wednesday"; break;
				case Thu: o_s << "Thursday"; break;
				case Fri: o_s << "Friday"; break;
				case Sat: o_s << "Saturday"; break;
				default:	o_s << "ERROR!";
			} 

	}











