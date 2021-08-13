# Linux Shell

**_This is an implementation of a basic Linux Shell in C using Linux System Calls and inbuilt C libraries_**

### HOW TO RUN?

##### DEPENDENCIES

1.  **[Git](https://git-scm.com/downloads)**
2.  **[GCC Compiler](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/)**

##### Clone this repository using the command

    git clone https://github.com/anoushkanarang/Linux-Shell.git

##### Change the current working directory to Linux-Shell

    cd Linux-Shell

##### run make to execute the program

    make

### ABOUT

<ul>
    <li>shell.c stores the source code of the shell.</li>
    <li>getcat.c, getdate.c, getls.c, getmkdir.c and getrm.c contain source code for cat, date, ls, mkdir, rm (external) commands respectively.</li>
    <li>Description.txt contains description of each command executed in the shell.</li>
    <li>writehistory.txt stores the history of the shell.</li>
    <li>The remaining text files store the data to be displayed when the help flag of respective commands is called.</li>
    <li>Makefile is used for compilation.</li>

</ul>   
 
### COMMANDS IMPLEMENTED
##### INTERNAL
<ol>
  <li>
    <a href="https://www.geeksforgeeks.org/exit-command-in-linux-with-examples/">exit</a> command is used to exit the shell where it is currently running. 
  </li>
  
  <li>
    <a href="https://www.geeksforgeeks.org/history-command-in-linux-with-examples/">history</a> command is used to view the commands previously executed on the shell. 
      <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
              --help: displays the help related information.
          </li>
          <li>
              -c: clears the history.
          </li>
      </ul>
  </li>
  
  <li>
    <a href="https://www.geeksforgeeks.org/echo-command-in-linux-with-examples/">echo</a> command is used to display line of text/string that are passed as an argument.
      <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
              -e: interprets \n as a new line character and prints everything after \n in a new line, doesn’t take inverted commas into account.
          </li>
          <li>
              -E: prints everything and doesn’t take inverted commas into account.
          </li>
      </ul>
  </li>
 
  <li>
    <a href="https://www.geeksforgeeks.org/pwd-command-in-linux-with-examples/">pwd</a> command is used to print the current directory. 
      <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
              --help: displays the help related information.
          </li>
          <li>
             -L: Softlink for the pwd command. 
          </li>
      </ul>
  </li>
  
  <li>
    <a href="https://www.geeksforgeeks.org/cd-command-in-linux-with-examples/">cd</a> command is used to change current working directory. 
      <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
            --help: displays the help related information.
          </li>
          <li>
            -L: Softlink for the cd command.
          </li>
      </ul>   
  </li>
    
</ol>

##### EXTERNAL

<ol>
  <li>
    <a href="https://www.geeksforgeeks.org/date-command-linux-examples/">date</a> command is used to display the system date and time.
    <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
             --help: displays the help related information.
          </li>
          <li>
              -u: displays date, time in UTC.
          </li>
      </ul>
  </li>
  
  <li>
    <a href="https://www.geeksforgeeks.org/cat-command-in-linux-with-examples/">cat</a> command reads data from the file and gives their content as output. 
      <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
              --help: displays the help related information.
          </li>
          <li>
              -n: displays the contents of a file preceding with line numbers. 
          </li>
      </ul>
  </li>
  
  <li>
    <a href="https://www.geeksforgeeks.org/mkdir-command-in-linux-with-examples/">mkdir</a> command is used to create directories.
      <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
            --help: displays the help related information.
          </li>
          <li>
             -v: It displays a message for every directory created (if the creation was successful or not)
          </li>
      </ul>
  </li>
 
  <li>
    <a href="https://www.geeksforgeeks.org/practical-applications-ls-command-linux/">ls</a> command lists directory contents of files and directories.
      <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
             --help: displays the help related information.
          </li>
          <li>
             -1: used to list each directory in a new line.
          </li>
      </ul>
  </li>
  
  <li>
    <a href="https://www.geeksforgeeks.org/rm-command-linux-examples/">rm</a> command is used to remove files, directories, symbolic links from the file system. 
      <h6> FLAGS IMPLEMENTED </h6>
      <ul>
          <li>
           --help: displays the help related information.
          </li>
          <li>
           -i: makes the command ask the user for confirmation before removing each file, you have to press y for confirm deletion, any other key leaves the file un-deleted.
          </li>
      </ul>   
  </li>
    
</ol>
   
### Sample Test Case

      echo hello world
      ls -1
      date -u
      mkdir five six seven
      pwd --help
      cat -n date.txt
      date
      history
      cd five
      pwd
      rm five
      exit
