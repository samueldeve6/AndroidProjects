// CPP program to solve Rat in a maze
// problem with backtracking using stack
  
#include <cstring>
#include <iostream>
#include <stack>
  
using namespace std;
  
#define N 4
#define M 5
  
class node {
public:
    int x, y;
    int dir;
  
    node(int i, int j)
    {
        x = i;
        y = j;
          
        // Initially direction 
        // set to 0
        dir = 0;
    }
};
  
// maze of n*m matrix
int n = N, m = M;
  
// Coordinates of food
int fx, fy;
bool visited[N][M];
  
bool isReachable(int maze[N][M])
{
    // Initially starting at (0, 0).
    int i = 0, j = 0;
      
    stack<node> s;
      
    node temp(i, j);
      
    s.push(temp);
  
    while (!s.empty()) {
  
        // Pop the top node and move to the
        // left, right, top, down or retract 
        // back according the value of node's
        // dir variable.
        temp = s.top();
        int d = temp.dir;
        i = temp.x, j = temp.y;
  
        // Increment the direction and
        // push the node in the stack again.
        temp.dir++;
        s.pop();
        s.push(temp);
  
        // If we reach the Food coordinates
        // return true
        if (i == fx and j == fy) {
            return true;
        }
  
        // Checking the Up direction.
        if (d == 0) {
            if (i - 1 >= 0 and maze[i - 1][j] and 
                                    visited[i - 1][j]) {
                node temp1(i - 1, j);
                visited[i - 1][j] = false;
                s.push(temp1);
            }
        }
  
        // Checking the left direction
        else if (d == 1) {
            if (j - 1 >= 0 and maze[i][j - 1] and 
                                    visited[i][j - 1]) {
                node temp1(i, j - 1);
                visited[i][j - 1] = false;
                s.push(temp1);
            }
        }
  
        // Checking the down direction
        else if (d == 2) {
            if (i + 1 < n and maze[i + 1][j] and 
                                    visited[i + 1][j]) {
                node temp1(i + 1, j);
                visited[i + 1][j] = false;
                s.push(temp1);
            }
        }
        // Checking the right direction
        else if (d == 3) {
            if (j + 1 < m and maze[i][j + 1] and 
                                    visited[i][j + 1]) {
                node temp1(i, j + 1);
                visited[i][j + 1] = false;
                s.push(temp1);
            }
        }
  
        // If none of the direction can take 
        // the rat to the Food, retract back 
        // to the path where the rat came from.
        else {
            visited[temp.x][temp.y] = true;
            s.pop();
        }
    }
  
    // If the stack is empty and
    // no path is found return false.
    return false;
}
  
// Driver code
int main()
{
    // Initially setting the visited
    // array to true (unvisited)
    memset(visited, true, sizeof(visited));
      
    // Maze matrix
    int maze[N][M] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };
  
    // Food coordinates
    fx = 2;
    fy = 3;
  
    if (isReachable(maze)) {
        cout << "Path Found!" << '\n';
    }
    else
        cout << "No Path Found!" << '\n';
          
    return 0;
}

