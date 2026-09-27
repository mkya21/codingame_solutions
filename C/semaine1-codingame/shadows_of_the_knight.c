#include <stdlib.h>
#include <stdio.h>

int strLenFunction(char text[]){
  int i = 0;
  for (i = 0; text[i] != '\0'; i++){};
  return i;
}

int main()
{
    int W;
    int H;
    scanf("%d%d", &W, &H);

    int N;
    scanf("%d", &N);

    int coordonnerXActuel;
    int coordonnerYActuel;
    scanf("%d%d", &coordonnerXActuel, &coordonnerYActuel);

    int YPosLaPlusHaut = 0;
    int YPosLaPlusBas = H - 1;
    int XPosLaPlusLeft = 0;
    int XPosLaPlusRight = W - 1;

    while (1) {
        char bomb_dir[4] = "";
        scanf("%s", bomb_dir);

        if (strLenFunction(bomb_dir) < 2){
            switch (bomb_dir[0]) {
            case 'U':
                YPosLaPlusBas = coordonnerYActuel - 1; 
                coordonnerYActuel = (YPosLaPlusHaut + YPosLaPlusBas) / 2;
                break;
            case 'R':
                XPosLaPlusLeft = coordonnerXActuel + 1; 
                coordonnerXActuel = (XPosLaPlusLeft + XPosLaPlusRight) / 2;
                break;
            case 'D':
                YPosLaPlusHaut = coordonnerYActuel + 1; 
                coordonnerYActuel = (YPosLaPlusHaut + YPosLaPlusBas) / 2;
                break;
            case 'L':
                XPosLaPlusRight = coordonnerXActuel - 1; 
                coordonnerXActuel = (XPosLaPlusLeft + XPosLaPlusRight) / 2;
                break;
            };
        } else {
            if (bomb_dir[0] == 'U' && bomb_dir[1] == 'R'){
                YPosLaPlusBas = coordonnerYActuel - 1;
                XPosLaPlusLeft = coordonnerXActuel + 1;
                
                coordonnerYActuel = (YPosLaPlusHaut + YPosLaPlusBas) / 2;
                coordonnerXActuel = (XPosLaPlusLeft + XPosLaPlusRight) / 2;

            } else if (bomb_dir[0] == 'U' && bomb_dir[1] == 'L') {
                YPosLaPlusBas = coordonnerYActuel - 1;
                XPosLaPlusRight = coordonnerXActuel - 1;
                
                coordonnerYActuel = (YPosLaPlusHaut + YPosLaPlusBas) / 2;
                coordonnerXActuel = (XPosLaPlusLeft + XPosLaPlusRight) / 2;

            } else if (bomb_dir[0] == 'D' && bomb_dir[1] == 'R'){
                YPosLaPlusHaut = coordonnerYActuel + 1;
                XPosLaPlusLeft = coordonnerXActuel + 1;
                
                coordonnerYActuel = (YPosLaPlusHaut + YPosLaPlusBas) / 2;
                coordonnerXActuel = (XPosLaPlusLeft + XPosLaPlusRight) / 2;

            } else if (bomb_dir[0] == 'D' && bomb_dir[1] == 'L'){
                YPosLaPlusHaut = coordonnerYActuel + 1;
                XPosLaPlusRight = coordonnerXActuel - 1;
                
                coordonnerYActuel = (YPosLaPlusHaut + YPosLaPlusBas) / 2;
                coordonnerXActuel = (XPosLaPlusLeft + XPosLaPlusRight) / 2;
            }
        }

        printf("%d %d\n", coordonnerXActuel,  coordonnerYActuel);
    }

    return 0;
}