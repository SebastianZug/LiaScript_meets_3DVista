<!--

author:   Sebastian Zug & André Dietrich
email:    sebatian.zug@informatik.tu-freiberg.de & andre.dietrich@informatik.tu-freiberg.de

-->

[![LiaScript](https://raw.githubusercontent.com/LiaScript/LiaScript/master/badges/course.svg)](https://liascript.github.io/course/?https://raw.githubusercontent.com/SebastianZug/LiaScript_meets_3DVista/main/README.md)

# 360°-Virtual Tour - TourDe360

3DVista erlaubt die Erstellung einer interaktiven 360°-Virtual Tour mit TourDe360/TDV Player. Diese Tour bietet immersive Panorama-Navigation mit Hotspots, integrierten PDF-Viewern und responsivem Design.

> Dieses Projekt zielte auf die prototypische Interation von 3DVista Lehr-LernInhalten in die Beschreibungssprache LiaScript. Dazu wurde ein Material von Frau Jette Schwick (TU Dresden) verwendet, das als Webseite vorlag. Die ursprüngliche Version war nativ nicht ausführbar. 

Das Vorliegende Repository enthält eine angepasste Version, die 

+ lokal 
+ auf GitHub Pages und 
+ drauf aufbauen in einem LiaScript Dokument 

lauffähig ist. 

Das Projekt findet sich auf Github unter https://github.com/sebastianzug/LiaScript_meets_3DVista. Die vorgenommenen Änderungen sind CHANGES.md und HISTORY.md dokumentiert.

### Lokale Entwicklung

1. **Repository klonen**

   ```bash
   # Repository von GitHub klonen
   git clone https://github.com/SebastianZug/LiaScript_meets_3DVista.git
   
   # In das Projektverzeichnis wechseln
   cd LiaScript_meets_3DVista
   ```

2. **Projektstruktur und Links evaluieren**

   ```bash
   # Symbolische Links überprüfen (sollten bereits vorhanden sein)
   ls -la lib locale
   
   # Verzeichnisstruktur anzeigen
   tree -L 2
   ```

3. **Lokalen Server starten**

   ```bash
   # Option 1: Python HTTP-Server (empfohlen)
   python3 -m http.server 8000
   
   # Option 2: Node.js live-server (falls installiert)
   npx live-server --port=8000
   
   # Option 3: PHP Development Server
   php -S localhost:8000
   ```

4. **Tour im Browser öffnen**

   - **Hauptseite:** http://localhost:8000
   - **Direkte index.html:** http://localhost:8000/index.html

> **Hinweis:** Die Tour benötigt einen HTTP-Server, da sie CORS-Requests für Medien und Skripte verwendet. Ein einfaches Öffnen der index.html-Datei im Browser funktioniert nicht.

### Live-Zugriff über GitHub Page

GitHub Pages bietet eine einfache  Möglichkeit, statische Webseiten direkt aus einem Repository zu hosten. Die Tour ist automatisch verfügbar, sobald Änderungen in den `main`-Branch gepusht werden. Die Konfiguration erfolgt über die Repository-Einstellungen unter "Pages" mit der Auswahl "Deploy from a branch" → `main` → `/ (root)`. Die `.nojekyll`-Datei im Repository-Root verhindert die Jekyll-Verarbeitung und ermöglicht die korrekte Darstellung aller Projektdateien.

Die Github Page wurde genutzt, um die Tour Online bereitzustellen. Die Umsetzung kann natürlich auch mit anderen Webservern erfolgen.

**Live-Demo:** https://sebastianzug.github.io/LiaScript_meets_3DVista/

### LiaScript Beispiel

Der Github Page Link kann direkt in ein LiaScript Dokument eingebunden werden, um die Tour direkt in einem Lehrinhalt einzubetten. Dazu einfach folgenden Link verwenden:

```
??[3DVista_example](https://sebastianzug.github.io/LiaScript_meets_3DVista/)
```

> Seien Sie sich bewusst, dass die Performance und das Nutzererlebnis je nach Endgerät und Netzwerkbedingungen variieren können. Auf meinem Rechner dauerte es etwa 20 Sekunden bis die Tour vollständig geladen war.

??[3DVista_example](https://sebastianzug.github.io/LiaScript_meets_3DVista/ "Beispielumsetzung einer 3DVista Lernumgebung in LiScript")

Diese README.md ist selbst ein LiaScript Dokument und kann, sofern das nicht schon mit dem Badge oben geschehen ist, auch direkt in LiaScript geöffnet werden unter:

https://liascript.github.io/course/?https://raw.githubusercontent.com/SebastianZug/LiaScript_meets_3DVista/main/README.md

## Hinweise

+ Möglicherweise sind noch nicht alle Funktionen der ursprünglichen Tour implementiert. Dies ist ein Prototyp, um die Machbarkeit zu demonstrieren. Ggf. fehlen zum Beispiel Videos oder einzelne pdf, die wegen ihrer Größe nicht in das Repository hochgeladen werden konnten.

+ Die Auflösung der Ausgabe könnte je nach Endgerät variieren. Hier wäre noch eine automatische Anpassung wünschenswert. Optimal ist ein Desktop-Rechner mit ausreichend Leistung und einem großen Bildschirm. Auf mobilen Geräten wurde die Darstellung nicht getestet.

## Lizenz

Projekt basiert auf TourDe360/TDV Player. Siehe entsprechende Lizenzbestimmungen in den lib-Ordnern.

Die Rechte bei den Inhalten des Kurses liegen bei Jette Schwick (TU Dresden).