#### vježba 3

Zadana je gotova klasa
* Dialog - bazna klasa za sve vrste dialoga
	
Napišite program koji podiže ovakav dijalog. U edit se upisuju x i y koordinata (u pikselima). 
* Klik na „Cancel“ uvijek zatvara dijalog, 
* Klik na „OK“ zatvara dijalog samo ako su unešeni brojevi i pomiče kursor na unesene koordinate

![dialog](/v3.jpg?raw=true)

Uputstva:
* u resursima kreirajte dijalog, id mu može ostati IDD_DIALOG1
* klasu za dijalog izvedite iz Dialog
* dodajte public član tipa POINT koji će čuvati koordinate
* funkcija IDD neka vraća id dijaloga
* u OnInitDialog postavite inicijalne vrijednosti iz člana u edite koristeći SetInt
* u OnOK pročitajte vrijednosti iz edita u član koristeći GetInt; ako GetInt baci iznimku vratite false
* u WinMain napravite objekt tipa dijalog, proslijedite trenutnu poziciju kursora ([GetCursorPos](https://msdn.microsoft.com/en-us/library/windows/desktop/ms648390%28v=vs.85%29.aspx)) u dijalog i pozovite DoModal
* ako DoModal vrati IDOK dijalog je zatvoren sa „OK“
* poziciju kursora možete postaviti sa [SetCursorPos](https://msdn.microsoft.com/en-us/library/windows/desktop/ms648394%28v=vs.85%29.aspx)

	

