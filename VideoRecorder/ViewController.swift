//
//  ViewController.swift
//  VideoRecorder
//
//  Created by 马良 on 2020/10/9.
//

import Cocoa

class ViewController: NSViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        view.setFrameSize(NSSize(width: 320, height: 240))

        let btn = NSButton.init(title: "Record", target: nil, action: #selector(onRecord))
        btn.frame = NSRect(x: 320 / 2 - 40, y: 240 / 2 - 15, width: 80, height: 30)
        btn.bezelStyle = .rounded
        btn.setButtonType(.pushOnPushOff)
        btn.target = self

        view.addSubview(btn)
    }

    @objc func onRecord() {
        open_media()
    }

    override var representedObject: Any? {
        didSet {
            // Update the view, if already loaded.
        }
    }


}

