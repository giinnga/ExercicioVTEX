setTimeout(function() {
		var t = new Trianglify({noiseIntensity: 0});
		var pattern;
		if (document.body.parentNode.offsetHeight == 0) {
			pattern = t.generate(window.innerWidth, window.innerHeight);
		} else {
			pattern = t.generate(document.body.parentNode.offsetHeight, document.body.parentNode.offsetHeight);
		}
		document.body.parentNode.setAttribute('style', 'background-image: ' + pattern.dataUrl);
	}, 1);
