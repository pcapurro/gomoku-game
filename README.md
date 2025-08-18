# gomoku-game

### « A simple game »

<br/>

The project has been created for Linux only and requires the following package:

```
libsfml-dev
```

Type `./gomoku-game` or `./gomoku-game --classic` to launch.

Type `./gomoku-game --shell` for a command line interface.

<br/>

**In both versions**: 

The game is following simple rules.

In order to win, you can :

**1** - Align at least 5 stones.

**2** - Capture at least 5 pairs of stones from the other player.

<br/>

The game paramaters are customizable by defining macros in the Makefile.

At the end of a game, a summary is written in the terminal.

<br/>

**In classical version**:

Use `LMB` to interact with the grid and place stones.

You can use `Left` and `Right` to navigate in the chronology of the game.

When a game is over, you can use `Enter` to restart the game.

You can use `Escape` to quit the game or simply click the cross in the window.

<br/>

**In shell version**:

Type the move you want to play using coordinates notation (e.g.: `0;0`, `21;4` ...).

Write `restart` to restart the game or `end` to end it and shut down the program.
