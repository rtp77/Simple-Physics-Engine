##2D 360 degrees

The working of the application is to make the green roller travel from the white ball to the white box wherever they be placed.
The initial placement is done with keyboard inputs for both the ball and the box, followed by an input to place the green roller on the ball.
Once ready for action
The green roller should travel towards the box smoothly.
This could be dont by creating a path, creating angles or any possible custom functions.

###Current Method (Only when ball is below and towards right of the box)

- Attain the starting positions (x and y of ball) and ending positions (x and y of box).
- Calculate the horizontal and vertical pixel distance.
- Using it break the longest distance (horizontal for now) into as many parts as the vertical distance (vertical for now).
- Store the path values while arranging it evenly.
- Calculate the time using desired speed of the roller and hypotenuse distance.
- Move the roller.

