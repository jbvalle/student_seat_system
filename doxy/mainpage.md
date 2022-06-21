<div id="top"></div>

<!-- PROJECT LOGO -->
<br />


<div align="center">

\image html ./images/logo.png width=50% height=50% 

<i>This project reads and saves a textfile in a generated hashtable and censores words depending on requested user input.</i>
<br />
<br />

</div>

<hr>

<!-- ABOUT THE PROJECT -->
## About The Project

<strong>1 Part: (SOLVED)<br /></strong>
* Open a text file and read the text row by row.<br />
* Separate words by these characters (" ", ".", "\n")<br />
* Store the values in a hashtable using dynamic linked lists.<br />
* Use the sum of character values as value to be hashed. E.g. Cat = (67+97+116) % 23<br />
* Words shall be stored in dynamically allocated memory<br />
* Print out the hash in a readable way. E.g. max 10 words per row.<br />

<strong>2 Part: (SOLVED)<br /></strong>
* The occurrence of words shall be counted instead of multiple entries in the list. <br />
* Add additional word separators:<br />
-  semicolon (;) <br />
-  colon (:)<br />
-  comma (,)<br />
-  question mark (?)<br />
-  tab (\t)<br />


<strong>3 Part: (SOLVED)<br /></strong>
* The lists shall always retain alphabetic order.

<strong>4 Part: (SOLVED)<br /></strong>
* Give the user a choice to select one bucket to output separately.
* Print out the entries in the Bucket.
* Let the user select one or more buckets and remove all words from the text which do not match to these selected buckets and write it to a new text file.

<strong>5 Part: (SOLVED)<br /></strong>
* Let the user select one or more buckets and censor all words from the text which match to these selected buckets and write it to a new text file.
* All word separators shall be copied to the new file in the correct places.

<strong>6 Part: (SOLVED)<br /></strong>
* Store the hash in a binary file
* Read and populate the hash from a file and append/count new words into it when the user wants to do this.

<strong>7 Part: (SOLVED)<br /></strong>
* The program arguments are handled by getopt(3).


<hr>


<!-- GETTING STARTED -->
## Getting Started

* Start by generating Binary file: Follow Installation instruction

### Installation

* Generate Binary File "./hashcount" by executing make in src/
   ```sh
   make
   ```

<hr>

<!-- USAGE EXAMPLES -->
## Usage

* Hashcount is able to generate Hashtable from any file index requested
* If no input text is explicitly mentioned in argument a default text file in TEXTFILES/default.txt is used
* The User is able to choose different options
* Example:
   ```sh
   ./hashcount -f input.txt -rc
   ```

<table style="width=110%" border="solid black">
    <tr ALIGN=LEFT>
        <th >OPTIONS</th>
        <th>DESCRIPTION</th>
    </tr>
    <tr ALIGN=LEFT>
        <th>-f path_rel_to_bin/filename.txt</th>
        <th>For specifying an input file declare a file name after the -f option i.e. -f input.txt</th>
    </tr>
    <tr ALIGN=LEFT>
        <th>-r</th>
        <th>This removes all keywords from a textfile by a chosen bucket. This requires no arguments.</th>
    </tr>
    <tr ALIGN=LEFT>
        <th>-c</th>
        <th>This censores all words except chosen buckets. This requires no arguments</th>
    </tr>
</table>

<hr>

<!-- USAGE EXAMPLES -->
## Example

* These examples serve as illustrations how this application could be run
* For inputting indices for removing and censoring words spaces or comma could be used
   ```sh
   ./hashcount -f input.txt -rc
   ```

\image html ./images/remove.png width=50% height=50% 
\image html ./images/censor.png width=50% height=50%


<hr>
<br />
<!-- CONTACT -->
## Contact

Author: John Bryan Valle
Email: jbvalle.jv@gmail.com
Date: 21.01.2022
<div id="top"></div>

<!-- PROJECT LOGO -->
<br />


<div align="center">

\image html ./images/logo.png width=50% height=50% 

<i>This project reads and saves a textfile in a generated hashtable and censores words depending on requested user input.</i>
<br />
<br />

</div>

<hr>

<!-- ABOUT THE PROJECT -->
## About The Project

<strong>1 Part: (SOLVED)<br /></strong>
* Open a text file and read the text row by row.<br />
* Separate words by these characters (" ", ".", "\n")<br />
* Store the values in a hashtable using dynamic linked lists.<br />
* Use the sum of character values as value to be hashed. E.g. Cat = (67+97+116) % 23<br />
* Words shall be stored in dynamically allocated memory<br />
* Print out the hash in a readable way. E.g. max 10 words per row.<br />

<strong>2 Part: (SOLVED)<br /></strong>
* The occurrence of words shall be counted instead of multiple entries in the list. <br />
* Add additional word separators:<br />
-  semicolon (;) <br />
-  colon (:)<br />
-  comma (,)<br />
-  question mark (?)<br />
-  tab (\t)<br />


<strong>3 Part: (SOLVED)<br /></strong>
* The lists shall always retain alphabetic order.

<strong>4 Part: (SOLVED)<br /></strong>
* Give the user a choice to select one bucket to output separately.
* Print out the entries in the Bucket.
* Let the user select one or more buckets and remove all words from the text which do not match to these selected buckets and write it to a new text file.

<strong>5 Part: (SOLVED)<br /></strong>
* Let the user select one or more buckets and censor all words from the text which match to these selected buckets and write it to a new text file.
* All word separators shall be copied to the new file in the correct places.

<strong>6 Part: (SOLVED)<br /></strong>
* Store the hash in a binary file
* Read and populate the hash from a file and append/count new words into it when the user wants to do this.

<strong>7 Part: (SOLVED)<br /></strong>
* The program arguments are handled by getopt(3).


<hr>


<!-- GETTING STARTED -->
## Getting Started

* Start by generating Binary file: Follow Installation instruction

### Installation

* Generate Binary File "./hashcount" by executing make in src/
   ```sh
      make
         ```

         <hr>

         <!-- USAGE EXAMPLES -->
## Usage

         * Hashcount is able to generate Hashtable from any file index requested
         * If no input text is explicitly mentioned in argument a default text file in TEXTFILES/default.txt is used
         * The User is able to choose different options
         * Example:
            ```sh
               ./hashcount -f input.txt -rc
                  ```

                  <table style="width=110%" border="solid black">
                      <tr ALIGN=LEFT>
                              <th >OPTIONS</th>
                                      <th>DESCRIPTION</th>
                                          </tr>
                                              <tr ALIGN=LEFT>
                                                      <th>-f path_rel_to_bin/filename.txt</th>
                                                              <th>For specifying an input file declare a file name after the -f option i.e. -f input.txt</th>
                                                                  </tr>
                                                                      <tr ALIGN=LEFT>
                                                                              <th>-r</th>
                                                                                      <th>This removes all keywords from a textfile by a chosen bucket. This requires no arguments.</th>
                                                                                          </tr>
                                                                                              <tr ALIGN=LEFT>
                                                                                                      <th>-c</th>
                                                                                                              <th>This censores all words except chosen buckets. This requires no arguments</th>
                                                                                                                  </tr>
                                                                                                                  </table>

                                                                                                                  <hr>

                                                                                                                  <!-- USAGE EXAMPLES -->
## Example

                                                                                                                  * These examples serve as illustrations how this application could be run
                                                                                                                  * For inputting indices for removing and censoring words spaces or comma could be used
                                                                                                                     ```sh
                                                                                                                        ./hashcount -f input.txt -rc
                                                                                                                           ```

                                                                                                                           \image html ./images/remove.png width=50% height=50% 
                                                                                                                           \image html ./images/censor.png width=50% height=50%


                                                                                                                           <hr>
                                                                                                                           <br />
                                                                                                                           <!-- CONTACT -->
## Contact

                                                                                                                           Author: John Bryan Valle
                                                                                                                           Email: jbvalle.jv@gmail.com
                                                                                                                           Date: 21.01.2022

