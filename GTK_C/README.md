# GTK programming with C

-	GTK stands for: **G**IMP **T**ool**K**it
-	Would you like to program an user interface with C? Here you may do this!

##	GTK is available for:

-	C
-	C++
-	Python
-	JavaScript
-	Rust
-	https://www.gtk.org/docs/language-bindings/index

###	Requirements

-	you know about the C programming language (I'm serious) => The code examples are written in pure C only.
-	since GTK4 also exists for a long time, **all** these examples were written with **GTK 3**
-	using glade for UI design; available in the software center (Linux); Windows: https://sourceforge.net/projects/gladewin32/
-	any editor of your choice (in that case Visual Studio Code)

###	How to install gtk library

-	Linux:

**for GTK 3:**
```
sudo apt install libgtk-3-dev
```

**for GTK 4:**
```
sudo apt install libgtk-4-dev
```

-	Windows: https://www.gtk.org/docs/installations/windows/

###	How to build the application
-	This application must be build with:

**GTK 3:**
```
gcc <flags of your choice, like -Wall> <source file(s)> -o <output file> `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
```

**GTK 4:**
```
gcc <flags of your choice, like -Wall> <source file(s)> -o <output file> `pkg-config --cflags --libs gtk+-4.0` -export-dynamic
```

**important:**
-	*It's required to use the packages including the flag "-export-dynamic", otherwise your application might not work correctly!*

####	Hint
-	Since GTK3 exists for a long time and GTK4 is also available, in GTK3 some functions may (now) be deprecated.

####	Take also a look to:
-	https://www.gtk.org/
-	https://www.gtk.org/docs/language-bindings/index
-	https://en.wikipedia.org/wiki/List_of_language_bindings_for_GTK

**Have fun!**