// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <string.h>
#include <bits/stdc++.h>
#include <dirent.h>

using namespace std;

string folder = "customtest5.2"; // folder to score
string filetype = "c";
string comment = "the data of customtest 5.2 created 27 Dec 2021"; // there must be only 1 line of comment

bool verify_strong_name = false;
bool score_folder = true; // score folders or score files
double minimum_file_size = 150; // in Byte, ignore too small files

/*===================================================================================================*/


void get_score (string path1, string path2, double &score1, double &score2, 
				double &size1, double &size2, int &nline) {
	FILE *fp;
	char path[1111];

	/* Open the command for reading. */
	string command = "ruby test_plagiarism.rb " + path1 + " " + path2;
	fp = popen(command.c_str(), "r");
	if (fp == NULL) {
		printf("Failed to run command\n" );
		exit(1);
	}

	/* Read the output a line at a time - output it. */
// 	while (fgets(path, sizeof(path), fp) != NULL) {
// 		printf("%s", path);
// 		score = atof(path);
// 	}
	fgets(path, sizeof(path), fp); 
	size1 = atof(path);
	
	fgets(path, sizeof(path), fp); 
	size2 = atof(path);

	fgets(path, sizeof(path), fp); 
	score1 = atof(path);
	
	fgets(path, sizeof(path), fp); 
	score2 = atof(path);
	
	fgets(path, sizeof(path), fp); 
	nline = atoi(path);

	pclose(fp);
}



string backslash (string fn) {
	string new_fn = "";
	
	for (uint i = 0; i < fn.size(); i++) {
		if (isspace(fn[i])) 
			new_fn += "\\";
		
		new_fn += fn[i];
	}
	
	return new_fn;
}



string get_ftype (string fn) {
	return fn.substr(fn.find_last_of(".") + 1);
}



string get_fname (string fn) {
	return fn.substr(0, fn.find_last_of("."));
}



// https://www.mtu.edu/umc/services/websites/writing/characters-avoid/
string illegal = "#%&\\{}<>*?/$!\'\":@+`|=";
// True if there is special character (not including space); 
// False if otherwise
bool verify (string fn) {
	string ftype = get_ftype(fn);
	if (ftype.size() < 5 && ftype != filetype) 
		return false;
	
	string name = get_fname(fn);
	
	// weak verification
	if (!verify_strong_name) 
		for (uint i = 0; i < illegal.size(); i++)
			if (name.find(illegal[i]) != std::string::npos) 
				return false;
			
	// strong verification
	if (verify_strong_name)
		for (uint i = 0; i < name.size(); i++)
			if (!isalnum(name[i]) && name[i] != '_' && !isspace(name[i]))
				return false;
			
	return true;
}



void loop_files() {
	// Find all files in folder
	// https://www.gnu.org/software/libc/manual/html_node/Directory-Entries.html
	DIR* dirp = opendir(("./" + backslash(folder)).c_str());
	struct dirent* dp;
	
	vector<string> filter, xfilter;
	while ((dp = readdir(dirp)) != NULL) {
		if (dp->d_type == DT_REG && verify(dp->d_name))
			filter.push_back(dp->d_name);
		else if (dp->d_type == DT_REG) 
			xfilter.push_back(dp->d_name);
	}
	(void)closedir(dirp);
	
	// Print name of files
	cerr << "List of valid files: ";
	for (uint i = 0; i < filter.size(); i++) 
		cerr << backslash(filter[i]) << ", "; 
	cerr << endl << endl;
	
	cerr << "List of invalid files: ";
	for (uint i = 0; i < xfilter.size(); i++) 
		cerr << xfilter[i] << ", "; 
	cerr << endl << endl;
	
	if (filter.size() < 2) {
		cerr << "Error: There are not enough files in folder!\n\n";
		return;
	}
	
	// Get scores and write data to file
	freopen("data.txt", "w", stdout);
	cout << "data" << endl;
	
	map<string, double> size;
	
	for (uint i = 0; i < filter.size() - 1; i++)
		for (uint j = i + 1; j < filter.size(); j++) {
			cerr << "-------------------------------------------------\n";
			cerr << filter[i] << ' ' << filter[j] << endl;
			string path1 = "../" + folder + "/" + backslash(filter[i]);
			string path2 = "../" + folder + "/" + backslash(filter[j]);
			
			if (size.count(path1) > 0 || size.count(path2) > 0) continue;
			
			double size1, size2;
			double score1, score2;
			int nline;
			get_score(path1, path2, score1, score2, size1, size2, nline);
			
			bool con = false;
			if (size1 < minimum_file_size && size.count(path1) <= 0) {
				size[path1] = size1;
				con = true;
			}
			if (size2 < minimum_file_size && size.count(path2) <= 0) {
				size[path2] = size2;
				con = true;
			}
			if (con) continue;
			
			printf("%s\t%.2f\t%s\t%.2f\t%d\n", filter[i].c_str(), score1, filter[j].c_str(), score2, nline);
		}
		
	cerr << "\nSkipped files:\n";
	for(auto it = size.cbegin(); it != size.cend(); ++it) 
		cerr << it->first << " " << it->second << "\n";
}



int main( int argc, char *argv[] ) {
	// Find all files in folder
	// https://www.gnu.org/software/libc/manual/html_node/Directory-Entries.html
	DIR* dirp;
	DIR* subdirp;
	struct dirent* dp;
	struct dirent* sdp;
	
	int n_folder = 0; // count from 0
	vector<string> filter, xfilter, subfilter[555];
	
	string path = "./" + folder;
	if ((dirp = opendir(path.c_str())) == NULL) {
		cerr << "Error: Cannot open " << path << endl;
		return 0;
	}
	while ((dp = readdir(dirp)) != NULL) {
		string pname = dp->d_name;
		
		if (dp->d_type == DT_DIR && verify(pname)) {
			filter.push_back(pname);
			string subpath = "./" + folder + "/" + pname;
			if ((subdirp = opendir(subpath.c_str())) == NULL) {
				cerr << "Error: Cannot open " << subpath << endl;
				return 0;
			}
			
			while ((sdp = readdir(subdirp)) != NULL) {
				if (sdp->d_type == DT_REG && verify(sdp->d_name))
					subfilter[n_folder].push_back(sdp->d_name);
				else if (sdp->d_type == DT_REG) 
					xfilter.push_back(pname + "/" + sdp->d_name);
			}
			n_folder++;
		}
		else if (dp->d_type == DT_DIR && pname != ".." && pname != ".") 
			xfilter.push_back(pname);
	}
	(void)closedir(dirp);
	
	// Print name of files
	cerr << "List of valid folders: \n";
	for (uint i = 0; i < filter.size(); i++) 
		cerr << filter[i] << "\n"; 
	cerr << endl << endl;
	
	cerr << "List of invalid files: \n";
	for (uint i = 0; i < xfilter.size(); i++) 
		cerr << xfilter[i] << "\n"; 
	cerr << endl << endl;
	
	if (filter.size() < 2) {
		cerr << "Error: There are not enough subfolders in folder!\n\n";
		return 0;
	}
	
	
	// Get scores and write data to file
	freopen("data.txt", "w", stdout);
	cout << comment << endl;
	
	map<string, double> size;
	
	for (uint i = 0; i < filter.size() - 1; i++)
		for (uint j = i + 1; j < filter.size(); j++) {
			cerr << "-------------------------------------------------\n";
			cerr << filter[i] << " & " << filter[j] << endl;
			
			string path1 = "../" + backslash(folder) + "/" + backslash(filter[i]);
			string path2 = "../" + backslash(folder) + "/" + backslash(filter[j]);
			
			int nline[22][22];
			double score[22][22];
			uint m = subfilter[i].size();
			uint n = subfilter[j].size();
			
			for (uint I = 0; I < m; I++) 
				for (uint J = 0; J < n; J++) {
					
					string spath1 = path1 + "/" + backslash(subfilter[i][I]);
					string spath2 = path2 + "/" + backslash(subfilter[j][J]);
			
					if (size.count(spath1) > 0 || size.count(spath2) > 0) {
						score[I][J] = nline[I][J] = 0;
						continue;
					}
					
					double size1, size2;
					double score1, score2;
					get_score(spath1, spath2, score1, score2, size1, size2, nline[I][J]);
					
					bool con = false;
					if (size1 < minimum_file_size && size.count(path1) <= 0) {
						size[path1] = size1;
						con = true;
					}
					if (size2 < minimum_file_size && size.count(path2) <= 0) {
						size[path2] = size2;
						con = true;
					}
					if (con) {
						score[I][J] = nline[I][J] = 0;
						continue;
					}
					score[I][J] = .5 * (score1 + score2);
				}
				
			/* Note:
			 * There are many ways to measure the final plagiarism score 
			 * between 2 students Anna and Bob from the score matrix such as
			 * 1. S1 = max(score[I][J]) for all I, J
			 *    --> The representation of score matrix
			 * 2. S2 = max(mean(sum(score[I][J?]))) for all I, and different J of rows
			 *    --> The best match of Bob according to Anna
			 * 3. S3 = max(mean(sum(score[I?][J]))) for all J, and different I of columns 
			 *    --> The best match of Anna according to Bob
			 * 4. S4 = max(S2, S3)
			 * 5. S5 = mean(S2, S3)
			 *    ...
			 */
			int final_nline = 0, indexI, indexJ;
			double final_score = 0;
			
			cerr << m << ' ' << n << endl;
			for (uint I = 0; I < m; I++) {
				for (uint J = 0; J < n; J++) {
					cerr << score[I][J] << ' ';
					if (final_score == score[I][J] && final_nline < nline[I][J]) {
						final_nline = nline[I][J];
						indexI = I, indexJ = J;
					}
					else if (final_score < score[I][J]) {
						final_score = score[I][J];
						final_nline = nline[I][J];
						indexI = I, indexJ = J;
					}
				}
				cerr << endl;
			}
			
			printf("%s\t%.2f\t%s\t%.2f\t%d", filter[i].c_str(), final_score, filter[j].c_str(), final_score, final_nline);
			if (m && n) printf("\t%s\t%s", subfilter[i][indexI].c_str(), subfilter[j][indexJ].c_str());
			printf("\n");
		}
		
	cerr << "\nSkipped files:\n";
	for(auto it = size.cbegin(); it != size.cend(); ++it) 
		cerr << it->first << " " << it->second << "\n";
		
	return 0;
}


