// Protocol/helper tests for index.html:  node web/test_protocol.js
const fs = require("fs"), path = require("path"), os = require("os"), assert = require("assert");
const html = fs.readFileSync(path.join(__dirname, "index.html"), "utf8");
const js = path.join(os.tmpdir(), "dmc100-app-" + process.pid + ".js");
fs.writeFileSync(js, html.match(/<script>([\s\S]*)<\/script>/)[1]);
const m = require(js);
fs.unlinkSync(js);

// power view: 230 V DC, bar 1.5 A DC, zero offset -0.02 A
const r = m.parseLine("R,1000,0,3,2,0,1,43660000,3fc00000,0,230.0,5aa500000000000000000000,2,bca3d70a");
const p = m.powerReading(r, 0);
assert(Math.abs(p.v - 230) < 1e-6 && Math.abs(p.a - 1.48) < 1e-6 && Math.abs(p.w - 340.4) < 1e-3);
const p2 = m.powerReading(m.parseLine("R,1000,1,3,1,0,1,43660000,3fc00000,1,230.0,5aa5,2,bca3d70a"), 0);
assert(Math.abs(p2.a - 1.5) < 1e-6 && p2.vAC && p2.aAC);   // AC current: no zero offset
// normal reading, old 12-field line
const n = m.parseLine("R,1,0,3,2,0,1,3fc00000,00000000,0,1.500,5aa5");
assert.equal(m.powerReading(n, 0), null);
assert.equal(m.siValue(n, 0), 1.5);
assert.equal(m.siValue(m.parseLine("R,1,2,8,-1,0,1,40200000,00000000,0,2.500,"), 0), 2500);  // kOhm
assert(isNaN(m.siValue(m.parseLine("R,1,2,9,-1,0,0,00000000,00000000,0,OL,"), 0)));
assert.equal(m.acdcName(2), "DC"); assert.equal(m.acdcName(1), "AC"); assert.equal(m.acdcName(-1), "");
// status / info lines
const s = m.parseLine("S,5000,0,2,0,0,1,0,4,1,0,1,9,0,0,1,1,1");
assert.equal(s.beep, 1); assert.equal(s.view, 2);
assert.equal(m.parseLine("S,5000,0,2,0,0,1,0,4,1,0,1,9,0,0,1,1").beep, undefined);
assert.equal(m.parseLine("S,5000,0,2,0,0,1,0,4,1,0,1,9,0,0,1,1,0,13").usb, 13);
const i = m.parseLine("I,DMC100-USB,4,V1.4,00000000,2,00050000,0,12");
assert.equal(i.sessionEnds, "0"); assert.equal(i.dmmCmds, "12");
assert.deepEqual(m.parseLine("OK,K"), { type: "OK", cmd: "K" });
assert.equal(m.parseLine("R,garbage"), null);
// formatting, splitter, CSV
assert.equal(m.fmtSI(340.4, "W", 4), "340.4 W");
assert.equal(m.fmtSI(1234.5, "W", 4), "1.234 kW");
const got = []; const sp = m.makeSplitter(l => got.push(l));
sp("OK,K\r\nS,1"); sp(",2\n"); assert.deepEqual(got, ["OK,K", "S,1,2"]);
assert(m.csvRow({ t: "x", ms: 1, mode: 0, unit: "V", text: "a,b", value: 1, si: 1, siUnit: "V",
  hold: 0, acdc: 2, view: 0, raw: "" }).includes('"a,b"'));
console.log("web protocol tests: all ok");
