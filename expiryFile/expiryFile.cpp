#include "stdafx.h"
#include "Start.h"
#include "tempFile.h"
#include "Exception.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	int ok;

	struct tm tm;
	time_t t;


	if (strptime("22.02.2017", "%d.%m.%Y", &tm) == NULL) {
		std::cout << "wrong" << std::endl;
	}

	tm.tm_hour = 12;
	tm.tm_min = 30;
	tm.tm_sec = 30;

	printf("year: %d; month: %d; day: %d;\n",
		tm.tm_year, tm.tm_mon, tm.tm_mday);
	printf("hour: %d; minute: %d; second: %d\n",
		tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("week day: %d; year day: %d\n", tm.tm_wday, tm.tm_yday);


	tm.tm_isdst = -1;      /* Not set by strptime(); tells mktime()
						   to determine whether daylight saving time
						   is in effect */
	t = mktime(&tm);
	if (t == -1) {
		std::cout << "wrong2" << std::endl;
	}
	printf("seconds since the Epoch: %ld\n", (long)t);

	std::cin >> ok;



/*Start start;
start.set_input(argc, argv);

try {
	start.handleInput();
	return 1;
}catch (Exception e){
	std::cerr << e.to_string() << std::endl;
	return 0;
}
catch (...) {
	std::cerr << "Someting goes horrible wrong!" << std::endl;
	return 0;
}
*/
}
