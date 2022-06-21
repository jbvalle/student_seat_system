<div id="top"></div>

<!-- PROJECT LOGO -->
<br />


<div align="center">

\image html ./images/logo.png width=50% height=50% 

<i>This project generates a seat tracking system, which registers all people occupying a possible seat. Additionally a coverage system is applied for a customized distribution, and a neighbour tracking register is implemented for displaying all direct and indirect neighbours</i>
<br />
<br />

</div>

<hr>

<!-- ABOUT THE PROJECT -->
## About The Project

<strong>1 Part: (SOLVED)<br /></strong>
* Implement a user interface<br />
* For this purpose the GTK3 Framework has implemented<br />

<strong>2 Part: (SOLVED)<br /></strong>
* Generate a seating pattern using costumized rows and columns <br />

<strong>3 Part: (SOLVED)<br /></strong>
* Assigning a seat after user input <br />

<strong>4 Part: (SOLVED)<br /></strong>
* Saving the entered Student ID and its seating position <br />

<strong>5 Part: (SOLVED)<br /></strong>
* Requesting and display all direct neighbours relative to a user defined student ID<br />

<strong>6 Part: (SOLVED)<br /></strong>
* Requesting and display all indirect neighbours relative to a user defined student ID<br />

## Pattern generation
### 25% Coverage has been implemented using following algorithm


\image html ./images/25cov_pattern.png width=15% height=15%
\image html ./images/row_col_deter_25cov.png width=15% height=15%

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

<hr>

