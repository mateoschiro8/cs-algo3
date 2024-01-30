#ifndef LCS
#define LCS

#include <vector>
#include <string>
using namespace std;

int lcs(string& x, string& y, vector<vector<int>>& c) {
     
    for(int i = 0; i <= x.size(); i++) 
		c[i][0] = 0; 
	for(int j = 0; j <= y.size(); j++) 
		c[0][j] = 0;

	for(int i = 1; i <= x.size(); i++) {
		for(int j = 1; j <= y.size(); j++) {
			if(x[i] == y[j]) 
				c[i][j] = c[i - 1][j - 1] + 1; 
			else
				c[i][j] = max(c[i][j - 1], c[i - 1][j]);
		}
	}		

    return c[x.size()][y.size()];  
}

void pruebaLCS() {

    string x = "952873164";
    string y = "293587416";
    vector<vector<int>> c(x.size() + 1, vector<int>(y.size() + 1, 0));

    cout << lcs(x, y, c) << endl;

    for(int i = 0; i < c.size(); i++) {
        for(int j = 0; j < c[0].size(); j++) {
            int k = c[i][j];
            if(k < 10 && k >= 0)
                cout << " " << k << " ";
            else
                cout << k << " ";
        }
        cout << endl;
    }
}

#endif //LCS