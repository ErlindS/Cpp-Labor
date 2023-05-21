# Kurzanleitung zur Benutzung Ihres Git-Repositoriums
Im Labor `cen1123` werden Änderungen an Ihrem Repositorium über
die Eingabe von `git`-Befehlen auf der Kommandozeile gemacht.
Als Kommandozeile wird das Programm `konsole` verwendet.

## Inbetriebnahme
### Klonen
Zu Beginn müssen Sie das Repositorium auf den Laborrechner übertragen:

	git clone git@gitlab.hs-pforzheim.de:cen1123_ss23/student/sejdiuer.git

### Arbeitsverzeichnis
Um Git-Befehle verwenden zu können, müssen Sie in das Arbeitsverzeichnis wechseln:

	cd ~/sejdiuer

### Identität
Bei der ersten Benutzung Ihres Klones müssen Sie dem Repositorium Ihre Identität mitteilen:

	git config user.name  "sejdiuer"
	git config user.email "sejdiuer@hs-pforzheim.de"

### Hinzufügen Ihrer ersten Datei
Öffnen Sie den Texteditor `kate` und kopieren Sie folgenden Code

	int main() {
		return 0;
	}

in das Editorfenster. Speichern Sie nun diese Datei unter:

	~/sejdiuer/main.cpp

Wenn Sie nun in Ihrer `konsole` den Befehl `ls` eingeben, dann sollten Sie
Ihre soeben erstellte Datei sehen.

Der aktuelle Projektstand soll nun abgegeben werden. Hierfür wird zunächst
die Datei `main.cpp` für die Abgabe markiert:

	git add main.cpp

Da wir nur die Datei `main.cpp` abgeben wollen, können wir nun die Abgabe als
abgeschlossen markieren und mit der Beschreibung `Meine erste Abgabe` versehen:

	git commit -m "Meine erste Abgabe"

Nun endlich können wir die Abgabe an den Git-Server übertragen:

	git push

## Umgang mit dem Git-Server im Laboralltag
### Sichern von Änderungen
In diesem Abschnitt werden Sie leider nichts neues lernen.
Oder anders herum: Sie können Ihr bisheriges Wissen anwenden.

Falls Sie Ihre Änderungen an der Datei `main.cpp` auf dem Git-Server sichern wollen, dann
brauchen Sie nur die Schritte

	cd ~/sejdiuer
	git add main.cpp
	git commit -m "Sinnvolle Beschreibung der AEnderung..."
	git push

wiederholen.
