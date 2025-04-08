# Input validation

Need to traverse through the ```input``` string for validation:

1. The first and foremost thing in validation is removing any comments from the ```input``` if presence. So the idea is what ever input similar to ``` shell > ls -la # this is a comment ``` will processed the sameway ``` shell > ls -la ```. The ``` # this is a comment ``` part in the ```input ``` will be explicitly ignored.

2. Trim – Remove isspace(3) characters from the start and the beginning of the ```input``` string. List of isspace(3) characters: ```{ ' ', '\f', '\n', '\r', '\t', '\v' }```.

3. Quote Check – Check whether the modified string (```stream```) contains any quotes (single or double), and ensure they are properly enclosed.

4. Special Character Check – Check if stream contains any special characters such as ```\\, &, ;, ,, {, (, ), }```. If any of these aforementioned characters are present outside of quotes, treat it as invalid syntax.

5. Surrounding Quotes – Check whether stream is entirely enclosed by either single quotes (```''```) or double quotes (```""```). If so, treat it differently as a single command.

# Extract token

In this shell program anything delimiter by ```<, <<, >>, >, |, ' ' ``` will treat as ```token```
Example ```shell > ls -la | wc -l ``` the input will break-down in to 02 tokens ``` ls -la ``` and ``` wc -l ```

1. Any character other mentioned ones here and belongs Special Character to will generate a syntax error.

2. Check the for the existance of meta character in ``` steram``` and decide the execution process base on the result. Here is the list characters considered as meat characters in this scope of project ```<, <<, >>, >, |, ' ' ```

3. As a start firt the program will look for ```|``` in the stream and divided in to sub-process, every sub process will wait for the output of the previous process

