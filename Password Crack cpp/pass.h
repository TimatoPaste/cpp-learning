#include <string>
#include <vector>

using namespace std;
class password{
	private:
		string pass;
		vector<string> strings;
		vector<int> indices = {0}; //"ones" place on the lower indices
	public:
		password(vector<string> stringsIn){
			strings = stringsIn;
		}
		
		void up(){
			indices[0]++;
			for(int a=0;a<indices.size();a++){
				if(indices[a]==strings.size()){
					indices[a] = 0;
					if(a+1==indices.size()){
						indices.push_back(0);
					}
					else{
						indices[a+1]++;
					}
				}
			}
		}
		string update(){
			pass = "";
			for(int a:indices){
				pass+=strings[a];
			}
			return pass;
		}
};