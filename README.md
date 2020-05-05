## What is Multi Segment Soil Moisture Sensor?
My Blog: https://reurl.cc/R4e82r

一般市面上常見的土壤感測器大多如下圖所示, 直接使用表面露出的金屬與土壤接觸,
並使用分壓電路由後端裝置的ADC讀取, 藉由土壤濕度不同而會有不同阻值來判斷目前的土壤濕度
<center><img src="https://github.com/TripleC-Light/Multi-segment-soil-moisture-sensor/blob/master/image/image-300x194.png?raw=true" width=150></center>

但使用此種方法有幾個缺點, 其中之一便是金屬部分與土讓接觸久了會氧化生鏽造成阻值變化,
另外一個缺點則是無感測到較深的土壤位置, 而且當水流較慢而造成土讓表層與深層濕度分布不均時也舞法感測
因此我在這邊提出一種電容式多段土壤感測器, 使用土壤當介電質, 因此濕度不同時電容值就會有變化,
優點是可以不用直接接觸土讓, 使用膠膜將感測器全部包裹起來就可以避免氧化, 並將感測器尺寸延長,
分佈多組電容感測器, 以達到感測不同深度土壤濕度的功能
感測器概念如下圖所示, 每組電極與左邊的接地形成一組電容, 土壤則為介電質
<center><img src="https://github.com/TripleC-Light/Multi-segment-soil-moisture-sensor/blob/master/image/image-1.png?raw=true" width=300></center>

將其與 Arduino相連如下圖所示
<center><img src="https://github.com/TripleC-Light/Multi-segment-soil-moisture-sensor/blob/master/image/image-2-768x514.png?raw=true" width=700></center>

然後使用修改 Arduino感測電容的 library CapacitiveSensor, 使其可以讀取 7組電容值
實體的手工感測器如下圖
<center><img src="https://github.com/TripleC-Light/Multi-segment-soil-moisture-sensor/blob/master/image/sensor.jpg" width=700></center>
透過 Ardunio讀取資料後, 使用 serial傳送至電腦做顯示, 結果如下
<center><img src="https://github.com/TripleC-Light/Multi-segment-soil-moisture-sensor/blob/master/image/GUI.jpg?raw=true" width=600>
使用了好一陣子, 的確不會有生鏽的情形, 讀值也都一直很平穩, 初步實驗似乎沒有太大的問題, 就分享給大家囉~


## About Me
 - My Blog : [愛德華空想科學誌](https://triplec-light.000webhostapp.com)
 - E-mail : TripleC.Light@gmail.com
 - LinkedIn : [Edward Chou](https://www.linkedin.com/in/edward-chou-42058912a)
 - Buy Me A Coffee : [Buy Me A Coffee](https://www.buymeacoffee.com/YrFKPo2)
 - Paypal : [Link](https://www.paypal.me/TripleCLight?locale.x=zh_TW)

 