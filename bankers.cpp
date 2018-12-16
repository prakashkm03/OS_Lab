#include<iostream> 
using namespace std; 

int main() 
{ 
	
	int P;
	cout<<"Enter no. of processes : ";
	cin>>P;
	int processes[P];

	cout<<"Enter process ids :"<<endl;
	for(int i=0;i<P;i++)
	{
		cin>>processes[i];
	}

	int R;
	cout<<"Enter total no. of resources : ";
	cin>>R;
	int avail[R];

	cout<<"Enter the available instances of resources:"<<endl;
	for(int i=0;i<R;i++)
	{
		cin>>avail[i];
	}

	int maxm[P][R],allot[P][R],need[P][R];

	cout<<"Enter maximum resources that can be allocated to processes "<<endl;
	for(int i=0;i<P;i++)
	{
		for(int j=0;j<R;j++)
		{
			cin>>maxm[i][j];
		}
	}

	cout<<"Enter the resources allocated to processes "<<endl;
	for(int i=0;i<P;i++)
	{
		for(int j=0;j<R;j++)
		{
			cin>>allot[i][j];
		}
	}

	// Calculating Need of each P 
	for (int i = 0 ; i < P ; i++) 
		for (int j = 0 ; j < R ; j++) 

			// Need of instance = maxm instance - 
			//				 allocated instance 
			need[i][j] = maxm[i][j] - allot[i][j]; 

   
	// Mark all processes as infinish 
	bool finish[P] = {0}; 

	// To store safe sequence 
	int ans[P]; 

	// Make a copy of available resources 
	int temp[R]; 
	for (int i = 0; i < R ; i++) 
		temp[i] = avail[i]; 

	// While all processes are not finished 
	// or system is not in safe state. 
	int count = 0; 
	while (count < P) 
	{ 
		// Find a process which is not finish and 
		// whose needs can be satisfied with current 
		// temp[] resources. 
		bool found = false; 
		for (int p = 0; p < P; p++) 
		{ 
			// First check if a process is finished, 
			// if no, go for next condition 
			if (finish[p] == 0) 
			{ 
				// Check if for all resources of 
				// current P need is less 
				// than temp 
				int j; 
				for (j = 0; j < R; j++) 
					if (need[p][j] > temp[j]) 
						break; 

				// If all needs of p were satisfied. 
				if (j == R) 
				{ 
					// Add the allocated resources of 
					// current P to the available/temp 
					// resources i.e.free the resources 
					for (int k = 0 ; k < R ; k++) 
						temp[k] += allot[p][k]; 

					// Add this process to safe sequence. 
					ans[count++] = p; 

					// Mark this p as finished 
					finish[p] = 1; 

					found = true; 
				} 
			} 
		} 

		// If we could not find a next process in safe 
		// sequence. 
		if (found == false) 
		{ 
			cout << "System is not in safe state"; 
			return false; 
		} 
	} 

	// If system is in safe state then 
	// safe sequence will be as below 
	cout << "In safe state.\nSafe"
		" sequence is: "; 
	for (int i = 0; i < P ; i++) 
		cout << ans[i] << " ";


	return 0; 
} 
