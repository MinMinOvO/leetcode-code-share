

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool contains[10]; // is contain idx
    bool *contain;
    for(int i=0; i<9; i+=3){
        for(int j=0; j<9; j+=3){
            memset(contains, 0, sizeof(contains));
            for(int _i=0; _i<3; ++_i){
                for(int _j=0; _j<3; ++_j){
                    if(board[i+_i][j+_j] == '.'){
                        continue;
                    }
                    contain = contains + board[i+_i][j+_j] - '0';
                    if(*contain){
                        return false;
                    }
                    *contain = true;
                }
            }
        }
    }
    for(int i=0; i<9; ++i){
        memset(contains, 0, sizeof(contains));
        for(int j=0; j<9; ++j){
            if(board[i][j] == '.'){
                continue;
            }
            contain = contains + board[i][j] - '0';
            if(*contain){
                return false;
            }
            *contain = true;
        }
    }
    for(int j=0; j<9; ++j){
        memset(contains, 0, sizeof(contains));
        for(int i=0; i<9; ++i){
            if(board[i][j] == '.'){
                continue;
            }
            contain = contains + board[i][j] - '0';
            if(*contain){
                return false;
            }
            *contain = true;
        }
    }
    return true;
}