# Instructions

# Wave 0: Intial Setup
## Identifier
1. With your partners choose a 3 letter unique identifier for your files.
1. Confirm with the instructor that this identifier is available.
## Fork/clone
1. ONE partner forks the repository.
1. That partner adds the others as collaborators.
1. EVERYONE clones the fork.
1. EVERYONE `cd`s into the repository and opens VS Code, reopening in a dev container. 
## Setting an upstream
1. EVERYONE checks their origin:

    ```git remote -v```

    This should show the fork as the origin.
1. EVERYONE adds an upstream:

    ```git remote add upstream UPSTREAM_CLONE_URL```

    UPSTREAM_CLONE_URL should be the clone URL for your cohort, NOT the fork your group made
1. EVERYONE checks their upstream

    ```git remote -v```

    origin and upstream should have different URLs
# Wave 1: Branching
1. ONE partner (partner A) should make an "dev" branch and switch to it:

    ```
    git branch dev
    git switch dev
    ```
1. That ONE partner (partner A) should push the dev branch to origin

    ```
    git push origin dev
    ```
1. The OTHER partners will still be on main. Doing a pull will bring down the new branch, which they can then switch to.

    ```
    git pull
    git switch dev
    ```
1. Everyone should now be on the `dev` branch. EVERYONE run `git status` to verify this.

ALL OF YOUR COMMITS SHOULD BE IN BRANCHES. DO NOT EVER MAKE NEW COMMITS DIRECTLY TO MAIN, ONLY PULLS/MERGES FROM UPSTREAM.

# Wave 2: Directory setup
In this section we will be setting up some directories and checking that pushing/pulling on our branches works. Please actually do this in 3 commits, alternating partners so we can check that all the pushing/pulling is working correctly. All of this will happen on the `dev` branch, `main` will remain unchanged!

As you go through, DO NOT COMMIT ANY CHANGES TO FILES OTHER THAN THE ONES FOR YOUR GROUP. This includes markdown files, source files, etc.

## Directory in src
1. VERIFY YOU ARE ON THE DEV BRANCH.
1. ONE partner should make a new directory inside the `src` directory. This new directory should be the 3 letter identifier of your group.
1. Inside the directory, make a new empty file named `.gitignore` NOTE THAT IT STARTS WITH A PERIOD AND IS ALL LOWER CASE. You must match the name exactly!
    > We are making this `.gitignore` so that git will pick up this directory in a commit. git does not track empty directories, so we will create an empty file to ensure the directory gets tracked. We will later be filling this with useful files, but for now we're just setting up the structure.
1. VERIFY AGAIN that you are on the dev branch.
1. add/commit/push new directory
1. The other partners should verify they are on the dev branch, then pull

## Directory in include
1. Have the OTHER partner follow the above steps to make a directory with your identifier in the `include` directory. Make sure to add a `.gitignore`
1. add/commit/push/pull

## Directory in graphics
1. Switch parnters again and repeat to create a subdirectory in `graphics`.

## Pull Request
Make a PR to the upstream. It should come from your `dev` branch. Your `main` branch should still be unchanged!

# Wave 3: Exploration
In this section you will be exploring the repository and looking at an example microgame.

1. EVERYONE make the game.
1. EVERYONE play the game. Fair warning: it is quite ugly and unfun right now and there is only one microgame.
1. AS A GROUP explore the below files TOGETHER. In a shared doc, answer the below questions TOGETHER. DO NOT SPLIT UP THE WORK.

## Files to Explore Closely (in this recommended order)
- `include/aub/aub_test_game.h`
- `src/aub/aub_test_game.cpp`
- `include/aub/player.h`
- `src/aub/player.cpp`
- `include/mj/mj_game.h`

## Questions to answer
Answer the below questions IN A FILE OUTSIDE OF THIS REPOSITORY (maybe a Google Doc?)

## Source Questions
1. What is the name of the class reposible for the "Leave the screen" microgame?
1. What is it a subclass of?
1. What instance variable(s) does the "Leave the screen" microgame have?
1. How long does this microgame last?
1. How does the game signal when to end early?
1. How often is `play` called?

## Research Questions
Answer the following questions. Consider using online searches or AI for help, but answer in your own words.

1. What does ```[[maybe_unused]]``` mean in C++?
1. What does ```override``` mean in C++?
1. What is a namespace in C++?



