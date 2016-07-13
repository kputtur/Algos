#include <iostream>
#include <vector>

using std::vector;

int findmaxindex(vector<double> valuebyweight) {
	 int maxindex = 0;
	 int length = valuebyweight.size();
	 
	 for ( int i = 0; i< length; i++) {
	    
	      if(valuebyweight[i] >= valuebyweight[maxindex]) 
		 maxindex = i;
	   }

		if( valuebyweight[maxindex] == 0)
			return -1;	

	  return maxindex;
  }

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	
			double value = 0.0;
			int maxindex = 0;
			vector<double> valuebyweight(values.size());		
		
			for(int i=0; i< weights.size(); i++) {
				valuebyweight[i] = values[i]/(double)weights[i];

			 }

			while(capacity != 0) {
				
					maxindex = findmaxindex(valuebyweight);

					 if ( maxindex == -1) break;

					if( capacity >= weights[maxindex] ) {
						
						capacity -= weights[maxindex];
						value += values[maxindex];
					//	std::cout<<"value:"<<value<<"\n";
						valuebyweight[maxindex] = 0;
					  }
				           else {
						   value += double(valuebyweight[maxindex]) * capacity;
						  //  std::cout<<"value"<<value<<"\n";
						   capacity = 0;
						}						
					} 

			return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
