# Contributing guidelines
Contributions are most welcome.

Create a PR with the function(s) you wish to contribute matching C code for. A GitHub Actions workflow will build the project. If the build produces a matching executable, then it can be merged.

## Coding conventions and style guide
Some conventions I’ve stuck to:

- Using “snake_case” for function names, i.e. `decode_data` instead of `DecodeData`. This helps distinguish game functions from Psy-Q library functions, which use PascalCase (i.e. `GsInitGraph`).
- *Tabs* for indentation. It occupies one character, and users can choose how many spaces that maps to in their text editor/IDE.
- Descriptive names that aren’t needlessly abbreviated.
- Opening braces for functions and control structures on new lines.

An example of a function and control structure using the above conventions:

```c
void some_foo_function(void)
{
	if (some_condition())
	{
		do_something();
	}
	else
	{
		do_something_else();
	}
}
```

However, I don’t program in C day to day, so if any one has a strong argument for a change to the above then please do suggest it!
