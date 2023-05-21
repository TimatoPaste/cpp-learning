#include <chrono>
class stopwatch{
	private:
		chrono::high_resolution_clock::time_point startTime;
		chrono::high_resolution_clock::time_point endTime;
	public:
		stopwatch(){
			
		}
		void start(){
			startTime = chrono::high_resolution_clock::now();
		}
		void stop(){
			endTime = chrono::high_resolution_clock::now();
		}
		double getDurSec(){
			return chrono::duration_cast<chrono::duration<double>>(endTime-startTime).count();
		}
};