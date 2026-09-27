
var inputs: string[] = readline().split(' ');
const W: number = parseInt(inputs[0]); // width of the building.
const H: number = parseInt(inputs[1]); // height of the building.
const N: number = parseInt(readline()); // maximum number of turns before game over.
var inputs: string[] = readline().split(' ');
let coordonnerXActuel: number = parseInt(inputs[0]);
let coordonnerYActuel: number = parseInt(inputs[1]);


let YPosLaPlusHaut: number = 0;
let YPosLaPlusBas: number = H - 1;
let XPosLaPlusLeft:number = 0;
let XPosLaPlusRight: number = W - 1;

while (true) {
    const bombDir: string = readline();
    if (bombDir.length < 2){
      switch(bombDir[0]) {
        case 'U':
          YPosLaPlusBas = coordonnerYActuel - 1; 
          coordonnerYActuel = Math.round((YPosLaPlusHaut + YPosLaPlusBas) / 2);
          break;
        case 'R':
          XPosLaPlusLeft = coordonnerXActuel + 1; 
          coordonnerXActuel = Math.round((XPosLaPlusLeft + XPosLaPlusRight) / 2);
          break;
        case 'D':
          YPosLaPlusHaut = coordonnerYActuel + 1; 
          coordonnerYActuel = Math.round((YPosLaPlusHaut + YPosLaPlusBas) / 2);
          break;
        case 'L':
          XPosLaPlusRight = coordonnerXActuel - 1; 
          coordonnerXActuel = Math.round((XPosLaPlusLeft + XPosLaPlusRight) / 2);
          break;
      };
    }else {
      if (bombDir[0] == 'U' && bombDir[1] == 'R'){
        YPosLaPlusBas = coordonnerYActuel - 1;
        XPosLaPlusLeft = coordonnerXActuel + 1;
                
        coordonnerYActuel = Math.round((YPosLaPlusHaut + YPosLaPlusBas) / 2);
        coordonnerXActuel = Math.round((XPosLaPlusLeft + XPosLaPlusRight) / 2);

      } else if (bombDir[0] == 'U' && bombDir[1] == 'L') {
        YPosLaPlusBas = coordonnerYActuel - 1;
        XPosLaPlusRight = coordonnerXActuel - 1;
                
        coordonnerYActuel = Math.round((YPosLaPlusHaut + YPosLaPlusBas) / 2);
        coordonnerXActuel = Math.round((XPosLaPlusLeft + XPosLaPlusRight) / 2);

      } else if (bombDir[0] == 'D' && bombDir[1] == 'R'){
        YPosLaPlusHaut = coordonnerYActuel + 1;
        XPosLaPlusLeft = coordonnerXActuel + 1;
                
        coordonnerYActuel = Math.round((YPosLaPlusHaut + YPosLaPlusBas) / 2);
        coordonnerXActuel = Math.round((XPosLaPlusLeft + XPosLaPlusRight) / 2);

      } else if (bombDir[0] == 'D' && bombDir[1] == 'L'){
        YPosLaPlusHaut = coordonnerYActuel + 1;
        XPosLaPlusRight = coordonnerXActuel - 1;
                
        coordonnerYActuel = Math.round((YPosLaPlusHaut + YPosLaPlusBas) / 2);
        coordonnerXActuel = Math.round((XPosLaPlusLeft + XPosLaPlusRight) / 2);
      }
    }
  console.log(`${coordonnerXActuel} ${coordonnerYActuel}`);
}
