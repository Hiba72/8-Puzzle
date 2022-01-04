//#include<iostream>
//using namespace std;
////Heuristic h2 = Number of tiles out of row + number of tiles out of column
//int calculateHeuristic(int S[][3]) {
//		 int r = 0,c=0;
//// Calculating tiles out of rows
//		 if (S[0][0] != 1)
//			r++;
//		 if (S[0][1] != 2)
//			r++;
//		 if (S[0][2] != 3)
//			r++;
//		 if (S[1][0] != 8)
//			r++;
//		 if (S[1][2] != 4)
//			r++;
//		 if (S[2][0] != 7)
//			r++;
//		 if (S[2][1] != 6)
//			r++;
//		 if (S[2][2] != 5)
//			r++;
//// Calculating tiles out of columns
//		 if (S[0][0] != 1)
//			 c++;
//		 if (S[1][0] != 8)
//			 c++;
//		 if (S[2][0] != 7)
//			 c++;
//		 if (S[0][1] != 2)
//			 c++;	 
//		 if (S[2][1] != 6)
//			 c++;
//		 if (S[0][2] != 3)
//			 c++;
//		 if (S[1][2] != 4)
//			 c++;
//		 if (S[2][2] != 5)
//			 c++;
//		 return r + c;
//}
//void swap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void showMatrix(int S[][3]) {
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << S[i][j] << " ";
//	}
//		cout << "\n";
//	}
//}
//int main(){
//	int Goal[3][3] = { { 1,2,3 },{ 8,0,4 },{ 7,6,5 } };
//	int Start[3][3] = { {2,8,3},{1,6,4},{7,0,5} };
//
//		int Left[3][3];
//		int Right[3][3];
//		int Up[3][3];
//		int Down[3][3];
//		int lh=1, rh=1,uh=1,dh=1,k,l;
//		while (lh != 0 && rh != 0 && uh != 0 && dh != 0) {
//			for (int i = 0; i < 3; i++) {
//				for (int j = 0; j < 3; j++) {
//					Left[i][j] = Start[i][j];
//					Right[i][j] = Start[i][j];
//					Up[i][j] = Start[i][j];
//					Down[i][j] = Start[i][j];
//				}
//			}
//			cout << "*** Parent matrix ***\n";
//			showMatrix(Start);
//			if (Start[0][0] == 0) {
//				k = 0;
//				l = 0;
//				swap(Right[k][l], Right[k][l + 1]);
//				rh = calculateHeuristic(Right);
//				cout << "*** Right ***\n";
//				showMatrix(Right);
//				swap(Down[k][l], Down[k + 1][l]);
//				dh = calculateHeuristic(Down);
//				cout << "*** Down ***\n";
//				showMatrix(Down);
//				if (rh <= dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Right[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Down[i][j];
//					}
//				}
//			}
//			else if (Start[0][1] == 0) {
//				k = 0;
//				l = 1;
//				swap(Left[k][l], Left[k][l - 1]);
//				lh = calculateHeuristic(Left);
//				cout << "*** Left ***\n";
//				showMatrix(Left);
//				swap(Right[k][l], Right[k][l + 1]);
//				rh = calculateHeuristic(Right);
//				cout << "*** Right ***\n";
//				showMatrix(Right);
//				swap(Down[k][l], Down[k + 1][l]);
//				dh = calculateHeuristic(Down);
//				cout << "*** Down ***\n";
//				showMatrix(Down);
//				if (lh <= rh && lh <= dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Left[i][j];
//					}
//				}
//				else if (rh < lh && rh < dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Right[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Down[i][j];
//					}
//				}
//			}
//			else if (Start[0][2] == 0) {
//				k = 0;
//				l = 2;
//				swap(Left[k][l], Left[k][l - 1]);
//				lh = calculateHeuristic(Left);
//				cout << "*** Left ***\n";
//				showMatrix(Left);
//				swap(Down[k][l], Down[k + 1][l]);
//				dh = calculateHeuristic(Down);
//				cout << "*** Down ***\n";
//				showMatrix(Down);
//				if (lh <= dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Left[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Down[i][j];
//					}
//				}
//			}
//			else if (Start[1][0] == 0) {
//				k = 1; 
//				l = 0;
//				swap(Right[k][l], Right[k][l + 1]);
//				rh = calculateHeuristic(Right);
//				cout << "*** Right ***\n";
//				showMatrix(Right);
//				swap(Up[k][l], Up[k - 1][l]);
//				uh = calculateHeuristic(Up);
//				cout << "*** Up ***\n";
//				showMatrix(Up);
//				swap(Down[k][l], Down[k + 1][l]);
//				dh = calculateHeuristic(Down);
//				cout << "*** Down ***\n";
//				showMatrix(Down);
//	
//				if (rh <= lh && rh <= uh && rh <= dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Right[i][j];
//					}
//				}
//				else if (dh <= lh && dh <= rh && dh <= uh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Down[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Up[i][j];
//					}
//				}
//			}
//				else if (Start[1][1] == 0) {
//				k = 1; 
//				l = 1;
//				swap(Left[k][l], Left[k][l - 1]);
//				lh = calculateHeuristic(Left);
//				cout << "*** Left ***\n";
//				showMatrix(Left);
//				swap(Right[k][l], Right[k][l + 1]);
//				rh = calculateHeuristic(Right);
//				cout << "*** Right ***\n";
//				showMatrix(Right);
//				swap(Up[k][l], Up[k - 1][l]);
//				uh = calculateHeuristic(Up);
//				cout << "*** Up ***\n";
//				showMatrix(Up);
//				swap(Down[k][l], Down[k + 1][l]);
//				dh = calculateHeuristic(Down);
//				cout << "*** Down ***\n";
//				showMatrix(Down);
//			 if (uh <= lh && uh <= rh && uh <= dh) {
//				for (int i = 0; i < 3; i++) {
//					for (int j = 0; j < 3; j++)
//						Start[i][j] = Up[i][j];
//				}
//			}
//				else if (lh <= rh && lh <= uh && lh <= dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Left[i][j];
//					}
//				}
//				else  if (rh <= lh && rh <= uh && rh <= dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Right[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Down[i][j];
//					}
//				}
//			}
//			else if (Start[1][2] == 0) {
//				k = 1;
//				l = 2;
//				swap(Left[k][l], Left[k][l - 1]);
//				lh = calculateHeuristic(Left);
//				cout << "*** Left ***\n";
//				showMatrix(Left);
//				swap(Up[k][l], Up[k - 1][l]);
//				uh = calculateHeuristic(Up);
//				cout << "*** Up ***\n";
//				showMatrix(Up);
//				swap(Down[k][l], Down[k + 1][l]);
//				dh = calculateHeuristic(Down);
//				cout << "*** Down ***\n";
//				showMatrix(Down);
//				if (lh <= uh && lh <= dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Left[i][j];
//					}
//				}
//				else if (uh <= lh && uh <= dh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Up[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Down[i][j];
//					}
//				}
//			}
//			else if (Start[2][0] == 0) {
//				k = 2; l = 0;
//				swap(Right[k][l], Right[k][l + 1]);
//				rh = calculateHeuristic(Right);
//				cout << "*** Right ***\n";
//				showMatrix(Right);
//				swap(Up[k][l], Up[k + 1][l]);
//				uh = calculateHeuristic(Up);
//				cout << "*** Up ***\n";
//				showMatrix(Up);
//				if (rh <= uh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Right[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Up[i][j];
//					}
//				}
//			}
//		else if (Start[2][1] == 0) {
//				k = 2; l = 1;
//				swap(Left[k][l], Left[k][l - 1]);
//				lh = calculateHeuristic(Left);
//				cout << "*** Left ***\n";
//				showMatrix(Left);
//				swap(Right[k][l], Right[k][l + 1]);
//				rh = calculateHeuristic(Right);
//				cout << "*** Right ***\n";
//				showMatrix(Right);
//				swap(Up[k][l], Up[k - 1][l]);
//				uh = calculateHeuristic(Up);
//				cout << "*** Up ***\n";
//				showMatrix(Up);
//				if (lh <= rh && lh <= uh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Left[i][j];
//					}
//				}
//				else if (rh <= lh && rh <= uh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Right[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Up[i][j];
//					}
//				}
//			}
//			else if (Start[2][2] == 0) {
//				k = 2; l = 2;
//				swap(Left[k][l], Left[k][l - 1]);
//				lh = calculateHeuristic(Left);
//				cout << "*** Left ***\n";
//				showMatrix(Left);
//				swap(Up[k][l], Up[k + 1][l]);
//				uh = calculateHeuristic(Up);
//				cout << "*** Up ***\n";
//				showMatrix(Up);
//				if (lh <= uh) {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Left[i][j];
//					}
//				}
//				else {
//					for (int i = 0; i < 3; i++) {
//						for (int j = 0; j < 3; j++)
//							Start[i][j] = Up[i][j];
//					}
//				}
//			}	
//		}
//		cout << "*** GOAL ***\n";
//		showMatrix(Start);
//
//	
//}
