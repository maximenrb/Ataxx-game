# Ataxx Game

An implementation of game Ataxx using C++ and Qt library. 
Project realized as part of my 2nd year of engineering school at ISEN Nantes.


## Game Play

Ataxx is a strategy board game that involves play by two parties on a seven-by-seven square grid. The object of the game is to make your pieces constitute a majority of the pieces on the board at the end of the game, by converting as many of your opponent's pieces as possible.

Each player begins with two pieces, blue and red. The game starts with the four pieces on the four corners of the board, with blue in the top left and bottom right and red on the other two. White moves first.

During their turn, players move one of their pieces either one or two spaces in any direction. Diagonal distances are equivalent to orthogonal distances. If the destination is adjacent to the source, a new piece is created on the empty departure square. Otherwise the piece on the source moves to the destination. After the move, all of the opponent player's pieces adjacent to the destination square are converted to the color of the moving player.

The game ends when all squares have been filled or one of the players can't play. The player with the most pieces wins. A draw may occur.

Exctact from [https://en.wikipedia.org/wiki/Ataxx](https://en.wikipedia.org/wiki/Ataxx)

## Usage

Launch game (go in /cmake-build-debug repertory) :
* Console mode :
```bash
./Mini_project --mode console
```
> To play in this mode : 
```bash
Player X > startRow startColumn arrivalRow arrivalColumn
```


* Graphic mode (with Qt) :
```bash
./Mini_project --mode graphic
```
* Mixed mode (console + graphic) :
```bash
./Mini_project --mode mixed
```

## Screenshot

* Graphic View:  
![Graphic View](https://lh3.googleusercontent.com/tNT0Vy_6az9Qxsyx4LwXVbaDCg-M8HWW5QC3HrlTkKvS1tdphdr9XqRJwfOfs9RhzT2gc9pRQDp3MvLsyaONbOZ2JFvcozMeHZOeLa3-5lB7ExATigmaB00ogLmNVTkXY_0HOL8iQ4f5JYM4jRr_58WsJ7kgkKkGdKp7cgClVDfdiwJo3_CuvbMhqP46ArBkfRG2Cscj-r61RALPLE4bTYn3tqdIowIT2WNc8lZa0ZKA3U74TNVNitIRxmgxplyf3Gd3DT7pm-09sglRZRXL7ymlrdfyoxovsJZ85-trQUXPNLvAYP6lrKNZ07uxcdUENRnH-PP0mKV5B6iePUOUdNhVKM0ie3j35CET9oZXJxYkIYHlrzfRE1bhqEB8pfiKnw3JnfdbjB3ABDt91bzQYhCZxkTz7lP57XrZBnNNOCrBE1UjtrXIx0e77k0dD92xGnhAHZdPwTlw6gYXVYxKsetDY5mB1OBiYNVXk68az0JqdLKsDaxBzUEqq_u0Obi9ip1zxUdaQk_a85z514ixPbgWiTO92CBOJxU9yLnLLvP7FTVDVFqkluewOyf4avL3hRbgjTrvMlUVuH2FNIr3R1aOU5qqBkEQ6UYX0zN1_ZZJSzoomc14s9zsxCdezX385vww7jHsvGdxZQZX0OVqmYcf8-6gy6gBQbDOOhKHjLIgYj5gqSAsC7yzevGABw0Dcy8BZX1HP3_9yJYBNZuCqK0=w502-h657-no)

* Console View :  
![Console View](https://lh3.googleusercontent.com/SkPsL9kw6li5h-h_iINZ6vO1RzBhPQ21OWA7uRRgv60Be0X4txbRyvd415IvHSgV7mqStC1SvaPON8Ii6-iedumwLdQTPNxKjbCcVEkxh8IK4ZxPc8zP4LG6Pla3dwI0rK0NOzOA9FM8u3Sr4ENxJjvfmAYxFsSrNe4oFTTI1rPUIXh5tHhE6K6xvtvLhdG07w1UkRG8lCpnkaMqilGKI5c7wAk-LtXojwybxks-0pqMT7pu_ugkBvKPVTEBYk6tZqW9DkUp2-nJNxHjnM7rENvIGjPHumFU192Y4rOvQsoqTZywlUWuK7foM1ZHB46-9rPiYcmMz6T0OAdzaMeZvUtovLcxjQnueslaKKAdkvnzNkP9oikvtauMmqZCaHRjkp0drBiex4z3F8FgpvbDLZgnsC3k7yzDbKA43H-j5aYpG6F5f2dWItaiwO5za0RUG4sHyy5B4k_o6GgbCPxTm8GhnBzWvYOFSxP92S6Qx_n962KmVPQJYIDszGrt_5s0y0g3s7e8prSnQYYaqG7HJs3jKlFjHmy5BrCcb-Y7vZQCRXaLUC1BUMQPijMzr0aY8uvs1Xy23whX79fIOqE29ArGVwAfBRekfBV4rMTFyvC_nicxsk0IOTDEJYq2mVH7i5Aa4opp55_YpJ_TAsf-IXMYAVUnsw=w282-h336-no)

## Configuration

You can edit startup configuration : go in /Controller/Game_Controller.cpp > launchGame()
* Add or edit pieces position :
```c++
this->setValue(line, column, 1);	// Add blue piece
this->setValue(line, column, 2);	// Add red piece
```
* Add obstacles where players can't play :
```c++
this->setValue(line, column, 3);	// Add obstacle
```

## Tools

* getoptpp : [https://code.google.com/archive/p/getoptpp/](https://code.google.com/archive/p/getoptpp/)
* termcolor : [https://github.com/ikalnytskyi/termcolor](https://github.com/ikalnytskyi/termcolor)
* clearLayout() function : [https://stackoverflow.com/questions/4272196/qt-remove-all-widgets-from-layout](https://stackoverflow.com/questions/4272196/qt-remove-all-widgets-from-layout)

##  Copyright

_Licence: GPL_  
_Author: Maxime NARBAUD_  
_First release date: 2019-06-10_

[https://github.com/maximenrb](https://github.com/maximenrb)