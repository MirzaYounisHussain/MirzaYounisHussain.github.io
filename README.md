# [My LinkedIn Profile](https://www.linkedin.com/in/mirzayounishussain)


# DATA STRUCTURES & ALGORITHMS (DSA)
## All Experiments in C

---

## 📂 Full Code
👉 [View Code on GitHub](https://github.com/MirzaYounisHussain/MirzaYounisHussain.github.io/blob/main/new.c)

👉 [Open Raw Code (Easy Copy)](https://raw.githubusercontent.com/MirzaYounisHussain/MirzaYounisHussain.github.io/main/new.c)

---    Sf,2-F5c%!jHahS

## 📌 How to Use
1. Open raw code  
2. Press Ctrl + A  
3. Press Ctrl + C  
4. Paste in compiler  

---

(function () {

    // Remove inline handlers
    document.querySelectorAll('*').forEach(el => {
        [
            'oncopy','onpaste','oncut','oncontextmenu',
            'onselectstart','ondragstart','onmousedown',
            'onmouseup','onkeydown','onkeypress'
        ].forEach(attr => el[attr] = null);

        el.removeAttribute('disabled');
        el.removeAttribute('readonly');
        el.style.userSelect = 'text';
        el.style.webkitUserSelect = 'text';
    });

    // Kill event blockers
    [
        'copy','paste','cut','contextmenu',
        'selectstart','dragstart',
        'keydown','keypress','mousedown'
    ].forEach(evt => {
        window.addEventListener(evt, e => {
            e.stopImmediatePropagation();
        }, true);
    });

    // Enable content editing
    document.body.contentEditable = true;

    // Force selectable text
    const style = document.createElement('style');
    style.innerHTML = `
        * {
            user-select: text !important;
            -webkit-user-select: text !important;
        }
    `;
    document.head.appendChild(style);

    console.log("Maximum restrictions removed");

})();
