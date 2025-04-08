Need to travesrse through the ```input``` string for validation
 * 1. Need to trim -> remove ```isspace(3)``` characters from start and the begining of the input string. List of isspace(3) caracters ``` {' ', \f', '\n', '\r', '\t', '\v'} ```
 * 2. Need to checked to varify wether the modified string (```stream```) has any quotes (single or double),and if those are properly enclosed.
 * 3. Need to check if "stream" consist any special characters susch as "\\&;,{()}" if any of these affro-mentioned characters in presense outside quotes treated as invalid syntax.
 * 4. Need to checked and varify whether "stream" is surrounded by either single quotes('') or double quotes(""). If quote-surrounded then treat it differently as a single command.
