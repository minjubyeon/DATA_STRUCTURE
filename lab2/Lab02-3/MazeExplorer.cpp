//
//  MazeExplorer.cpp
//  Lab02
//
//  Modified by Jeman Park on 2026/03/31.
//

#include "MazeExplorer.h"

void printLocation(location point){
    cout << "[" << point.row << "][" << point.col << "]" << endl;
}

bool mazeExplorer(char map[][MAZE_SIZE], location entryPoint, location exitPoint){
    StackType<location> tempStack;
    tempStack.push(entryPoint);
    
    /* Implement the function here (Lab 02-3) */
    // This function explores "map" to find the path from "entryPoint" to "exitPoint" using STACK
    // it should prints all visited points.
    // it returns true, if it successfully finds the path
    // otherwise, it returns false
    // When there are multiple possible paths from the current point, the priority is "upward ↑" -> "rightward →" -> "downward ↓" -> "leftward ←"
    //
    // For details, check the PDF slides!
    
    
    // 이동할 수 있는 방향 (위, 오른쪽, 아래, 왼쪽)
    int moveX[4] = { -1, 0, 1, 0 };
    int moveY[4] = { 0, 1, 0, -1 };

    // 미로 탐색 함수
        while (!tempStack.isEmpty()) {
            location current = tempStack.pop();

            int x = current.row;
            int y = current.col;

            // 종료 지점에 도달한 경우
            if (x == exitPoint.row && y == exitPoint.col) {
                printLocation(current);
                return true;
            }

            // 범위를 벗어나거나 막힌 길이거나 이미 방문한 경우
            if (x < 0 || x >= MAZE_SIZE || y < 0 || y >= MAZE_SIZE || map[x][y] != '0') {
                continue;
            }

            // 현재 위치를 지나간 셀로 표시하고 좌표 출력
            map[x][y] = '.';
            printLocation(current);

            // 4가지 방향으로 이동 (역순으로 스택에 넣음)
            for (int i = 3; i >= 0; i--) {
                int newX = x + moveX[i];
                int newY = y + moveY[i];

                if (newX >= 0 && newX < MAZE_SIZE && newY >= 0 && newY < MAZE_SIZE && map[newX][newY] == '0') {
                    tempStack.push({ newX, newY });
                }
            }
        }

        // 경로가 없을 경우
        return false;

    }