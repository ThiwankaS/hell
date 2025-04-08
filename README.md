Need to traverse through the ```input``` string for validation:

1. Trim – Remove isspace(3) characters from the start and the beginning of the input string. List of isspace(3) characters: ```{ ' ', '\f', '\n', '\r', '\t', '\v' }```.

2. Quote Check – Check whether the modified string (```stream```) contains any quotes (single or double), and ensure they are properly enclosed.

3. Special Character Check – Check if stream contains any special characters such as ```\\, &, ;, ,, {, (, ), }```. If any of these aforementioned characters are present outside of quotes, treat it as invalid syntax.

4. Surrounding Quotes – Check whether stream is entirely enclosed by either single quotes (```''```) or double quotes (```""```). If so, treat it differently as a single command.
