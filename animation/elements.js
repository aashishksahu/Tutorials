function getRandomInt(min, max) {
    /*
        function generates random numbers in a given range
        source: https://developer.mozilla.org/en-US/docs/Web/
                JavaScript/Reference/Global_Objects/Math/random
     */
    
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min)) + min;
}

function createcircle() {

    // get the coordinates of the centeral dot
    var centerCircle = document.getElementById("center");
    var circleCoord = centerCircle.getBoundingClientRect();

    // to create a circle we need a center
    var h = (circleCoord.right + circleCoord.left) / 2;
    var t = (circleCoord.bottom + circleCoord.top) / 2;

    // we also need a radius
    var radius = 200;

    // array to store all the circles on the circumference
    var circleList = new Array();

    // creating multiple circles
    for (let i = 1; i <= 360; i += 9) {
        // evaluating a point on the circumference of a circle
        var x = parseInt(radius * Math.cos(i) + h);
        var y = parseInt(radius * Math.sin(i) + t);

        // creating circle on the above coordinates
        let new_circle = document.createElement("div");
        new_circle.className = "circle";
        //setting margin as per the coordinates
        new_circle.style.marginTop = "" + y - 15 + "px";
        new_circle.style.marginLeft = "" + x - 15 + "px";
        document.getElementById("container").appendChild(new_circle);

        // push each circle element
        circleList.push(new_circle);
    }

    // calling animator function
    animate(circleList);
}

function animate(elementList) {
    for (c in elementList) {
        // store the original postion to revert back to
        let orgPos = elementList[c].getBoundingClientRect();

        // get the center of the circle
        var p = (orgPos.right + orgPos.left) / 2;
        var q = (orgPos.bottom + orgPos.top) / 2;
        // generating random position
        var rand_x = getRandomInt(q, q + 300);
        var rand_y = getRandomInt(p, p + 300);

        //var setPos = document.querySelector(".circle");
        elementList[c].style.setProperty('--position-top', rand_y + 'px');  // not working
        elementList[c].style.setProperty('--position-left', rand_x + 'px'); // not working
        console.log("kbfwfi")
    }

}
  /*  
    var rad = 200;
    // loop over all the circles
    for (c in elementList) {
        // store the original postion to revert back to
        let orgPos = elementList[c].getBoundingClientRect();

        // get the center of the circle
        var p = (orgPos.right + orgPos.left) / 2;
        var q = (orgPos.bottom + orgPos.top) / 2;
        // generating random position
        var rand_x = getRandomInt(q, q + 300);
        var rand_y = getRandomInt(p, p + 300);

        // initial position
        pos_x = q;
        pos_y = p;

        console.log("pos_x: "+pos_x+"rand_x: "+rand_x);
        

        // creating a timeout function that calls a function for 
        // specified duration
        var id = setInterval(animFN, 1);

        function animFN () {
            if (pos_x == rand_x && pos_y == rand_y) {
                clearInterval(id);
            } else {

                if(pos_x>=rand_x){
                    pos_x--;
                }
                else{
                    pos_x++;
                }

                if(pos_y>=rand_y){
                    pos_y--;
                }
                else{
                    pos_y++;
                }

                elementList[c].style.marginTop = pos_x + 'px';
                elementList[c].style.marginLeft = pos_y + 'px';
            }
        }
        
    }    
    
}
*/