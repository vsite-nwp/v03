#### vježba 3

Zadana je (u _namespaceu_ `vsite::nwp`) gotova klasa
* `dialog` - bazna klasa za sve vrste dijaloga
	
Napišite program koji podiže ovakav dijalog. U _edit_ se upisuju x i y koordinata (u pikselima). 
* Klik na _Cancel_ uvijek zatvara dijalog, 
* Klik na _OK_ zatvara dijalog samo ako su unešeni brojevi i pomiče kursor na unesene koordinate

![dialog](/v3.jpg?raw=true)

Uputstva:
* u resursima kreirajte dijalog, id mu može ostati `IDD_DIALOG1`
* klasu za dijalog izvedite iz `vsite::nwp::dialog`
* dodajte _public_ član tipa `POINT` koji će čuvati koordinate
* funkcija `idd` neka vraća id dijaloga
* u `on_init_dialog` postavite inicijalne vrijednosti iz člana u _edite_ koristeći `set_int`
* u `on_ok` pročitajte vrijednosti iz _edita_ u član koristeći `get_int`; ako `get_int` baci iznimku vratite `false`
* u `WinMain` napravite objekt tipa dijalog, proslijedite trenutnu poziciju kursora ([GetCursorPos](https://msdn.microsoft.com/en-us/library/windows/desktop/ms648390%28v=vs.85%29.aspx)) u dijalog i pozovite `do_modal`
* ako `do_modal` vrati `IDOK` dijalog je zatvoren sa _OK_
* poziciju kursora možete postaviti sa [SetCursorPos](https://msdn.microsoft.com/en-us/library/windows/desktop/ms648394%28v=vs.85%29.aspx)
